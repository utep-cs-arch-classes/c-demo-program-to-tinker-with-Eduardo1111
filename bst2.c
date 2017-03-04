#include<stdio.h>
#include<string.h>
#include <ctype.h>
#include <stdlib.h>
#define MAX_NAME_LEN 170
#define START_DEPTH 0

typedef struct TreeNode{//Struct containing Treenode members
    char name[MAX_NAME_LEN];
    //  char name;
    struct TreeNode *left;
    struct TreeNode *right;
    // struct TreeNode_ *root;
}TreeNode;
//Method signatures declared before main()
TreeNode* read_from_file( char* file);
TreeNode* insert(TreeNode* node,  char *name);
TreeNode* create_node(char *name);



TreeNode* read_from_file(char* file){//Method to read from textfile, pulls names and inserts into the tree
    
    TreeNode *root = NULL;
    FILE *input = fopen(file, "r");
    char name[MAX_NAME_LEN];//Storing each name here
    while(!feof(input)){//While *input can read names off of file, keep going
        while(fgets(name, 170,input) != NULL){
            //HOW TO GET STRING INTO ROOT
            insert(root, name);//Immediately insert each name pulled into the tree
            printf("%s", root);//Show if null root is replaced by name
            puts(name);//Test to see if names are being pulled from the textfile read
            // display_tree(root, START_DEPTH);
        }fclose(input);
        return root;
    }
}

TreeNode* insert(TreeNode* node,  char *name){
    //TreeNode* insert(TreeNode* node, char name){
        if(node == NULL)
        // node == create_node(name);
        // create_node(name)=node;
        create_node(name);//Creating a node, passing in name (read from file)
        else if( node != NULL){//Sorting the names into either left or right positions
            if(strcmp(name, node->name)<0)
            node->left = insert(node->left, name);
            else if (strcmp(name,node->name) >0)
            node->right = insert(node->right,name);
        }
        return node;
    }
    
    TreeNode* create_node(  char *name){//Creating a node
        
        TreeNode * node;
        node = (TreeNode*)malloc(sizeof(TreeNode));//Allocating memory to node
        // name[0] = (char*)malloc(20*sizeof(char));
        // name[1]=(char*)malloc(20*sizeof(char));
        
        strcpy(node->name, name);
        node->left=NULL;//Setting both the left and right nodes to null
        node->right=NULL;
        return node;
    }
    
    
    void inorder (TreeNode *root){//Reccursively print out the tree
        if (root != NULL){
            inorder(root->left);
            printf("%s n", root->name);
            inorder(root->right);
        }
    }
    
    
    int main(){
       
        char name[MAX_NAME_LEN];
        TreeNode* root = NULL;//Declaring root to be used
        read_from_file("mytext.txt");//Calling read from file method to pull names from file and store into tree
        inorder(root);//Print out the tree (names will be shown)
    }