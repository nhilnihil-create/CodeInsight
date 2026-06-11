#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
int main(void){
   int X;
   cin>>X;
   
   int ans;
   int maxAns=1;
   
       for(int i=2;i<32;i++){
           for(int j=2;j<10;j++){
               ans=pow(i,j);
               if(ans>X){
                   break;
               }
               maxAns=max(maxAns,ans);
           }
       }
       cout<<maxAns<<endl;
   
   
   
   
}