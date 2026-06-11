#include<iostream>
using namespace std;
int main(){
    int A, B, K,i;
    cin>>A>>B>>K;
    if((B-A+1)/2<K){
        for(i=0;i<=B-A;i++){
            cout<<A+i<<" ";
        }
    }else{
        for(i=0;i<K;i++){
            cout<<A+i<<" ";
        }
        for(i=K-1;i>=0;i--){
            cout<<B-i<<" ";
        }
    }
    return 0;
}