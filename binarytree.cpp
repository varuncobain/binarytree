#include"iostream"
#include"queue"
using namespace std;

class node{
    public:
    int  data;
    node* left;
    node* right;

    node(int data){
        this->data = data;
        this->left = NULL;
         this->right = NULL;
    }

};

node* buildtree(node* root){
    cout<<"give data to this node "<<endl;
    int data;
    cin>>data;
    root = new node(data);
    if(data == -1){
        return NULL;
    }
    cout<<" give data to left of "<<data<<endl;
    root->left = buildtree(root->left);
    cout<<" give data to right of" <<data <<endl;
    root->right = buildtree(root->right);
    return root;
    
}

void levelorder(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* temp = q.front();
        
        
        q.pop();

        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
        
            if(temp->right){
                q.push(temp->right);
    
             } 
        }
        
    
        
        

        //10 5 3 -1 -1 -1 11 12 -1 -1 -1
  
    }
}

int maxheight(node* root){
    if(root==NULL){
        return 0;
    }

    int left = maxheight(root->left);
    int right = maxheight(root->right);
    int ans = max(left,right) +1 ;
    return ans;
}



int main(){
    node* root = NULL;
    root=buildtree(root);
    cout<<"done"<<endl;
    cout<<root->left->data<<endl;
    cout<<"data at root is "<<root->data<<endl;
    cout<<"levelorder traversal is "<<endl;
    levelorder(root);
    int j = maxheight(root);
    cout<<"max height of tree is "<<j<<endl;

    return 0;
}
