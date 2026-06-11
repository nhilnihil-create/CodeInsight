#include <iostream>
using namespace std;

int main(){
    int n,i;
    char s;
    cin>>n;
    while(true){
        i++;
        cin>>s;
        if(s=='Y'){
            cout<<"Four"<<endl;
            break;
        }
        if(i==n){
            cout<<"Three"<<endl;
            break;
        }
        
    }
    
    return 0;
    

    
}
