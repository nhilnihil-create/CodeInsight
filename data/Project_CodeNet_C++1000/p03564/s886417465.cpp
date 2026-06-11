#include <iostream>
using namespace std;

int main(){
    int a=1,ai1,ai2;
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        ai1=a*2;
        ai2=a+k;
        if(ai1<ai2){
            a=ai1;
        }else{
            a=ai2;
        }
    }
    cout<<a<<endl;
    
}

    
