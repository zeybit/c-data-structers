#include <iostream>
class Node{
    public:
    int data;
    Node *left,*right;
      Node(int item) {
            data = item;
            left = right = NULL;
        }
};
using namespace std;
//function for calculating height
 int height(Node *node){
     if(node==NULL){
       return 0;
         
     }
     else  {
         int leftHeigt=height(node->left);
         int rightHeight=height(node->right);
          if(leftHeigt>rightHeight)
          {
              return (leftHeigt+1);
          }
           else
          {
              return (rightHeight+1);
          }
     }
 }
 //current level
 void printCurrentLevel(Node* root, int level) {
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->data << " ";
    else if (level > 1) {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
} 
//level order
void printLevelOrder(Node* root) {
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}
void printReverseLevelOrder(Node* root) {
    int h = height(root);
    int i;
    for (i = h; i >= 1; i--)
        printCurrentLevel(root, i);
}

 //function preorder
 void printPreorder(Node* node) {
    if (node == NULL){
        cout<<endl<<"Nothing, its end of branch";
        return;
	}
    cout << endl<<"print node data: "<< node->data << " ";
    cout << endl<<"Now call left side of "<< node->data; /* First print node data itself */
    printPreorder(node->left); /* Then recur on left tree */
    cout << endl<<"Done with left, now call right side of "<< node->data;
    printPreorder(node->right); /* Finally recur on right subtree */
    cout << endl<<"Done with right side of "<< node->data;
}

//in order
void printInorder(Node *node) {
     if(node==NULL){
       return ;
         
     }
     else  { 
         printInorder(node->left);
         cout<<node->data<<endl;
        printInorder(node->right);
     }
}
//post order
void printPostorder(Node* node) {
    if (node == NULL)
        return;
    printPostorder(node->left); /* First recur on left tree */
    printPostorder(node->right); /* Then recur on right subtree */
    cout<< node->data << " "; /* Lastly print parent node data */
}

int main()
{
    Node *root=new Node(45);
    
    root->left=new Node(5);
    root->right=new Node(35);
    root->left->left=new Node(4);
    root->left->right=new Node(6);
    
    root->right->right=new Node(36);
 root->right->left=new Node(33);
 
/* cout<<"height of binary tree:"
 <<height(root);
 printPreorder(root);
 cout<<endl;
 cout<<"for in order:"<<endl;
 printInorder(root);
 printPostorder(root);*/
 printPostorder(root);
    return 0;
}
