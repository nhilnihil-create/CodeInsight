#include <iostream>
#include<bits/stdc++.h>
#define rep(k,i,n) for(int i=k;i<n;++i)
using namespace std;
int N,A,B,P,c[3]={0};
int main(void){
    // Your code here!
    cin>>N;
    cin>>A>>B;
    rep(0,i,N){
        cin>>P;
        if(A>=P){
            ++c[0];
        }else if(A<P &&P<=B){
            ++c[1];
        }else{
            ++c[2];
        }
    }
    cout<<min(c[0],min(c[1],c[2]));
}
