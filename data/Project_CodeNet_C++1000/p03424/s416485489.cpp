#include <iostream>
using namespace std;

int main(){
    int n,count=3;
    char s;
    
    cin>>n;
    
    for(int i=0;i<n;i++){
        cin>>s;
        if(s=='Y'){
            count=4;
            break;
        }
    }
    
    if(count==3)
        cout<<"Three"<<endl;
    else if(count==4)
        cout<<"Four"<<endl;
}
