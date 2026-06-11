#include<iostream>
using namespace std;

int main(){
    int a,b,n;
    cin>>a>>b>>n;
    if(b-a+1>=2*n){
        for(int i=0;i<n;i++){
            cout<<a+i<<endl;
        }
        for(int i=n-1;i>=0;i--){
            cout<<b-i<<endl;
        }
    }else{
        for(int i=a;i<=b;i++){
            cout<<i<<endl;
        }
    }
    return 0;
}