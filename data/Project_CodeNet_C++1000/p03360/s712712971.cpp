#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
int main(void){
   int A,B,C,K;
   cin>>A>>B>>C>>K;
   int X=max(A,max(B,C));
   rep(i,K){
       X*=2;
   }
   if(max(A,max(B,C))==A){
       cout<<X+B+C<<endl;
   }
   else if(max(A,max(B,C))==B){
       cout<<X+A+C<<endl;
   }
   else{
       cout<<X+A+B<<endl;
   }
}