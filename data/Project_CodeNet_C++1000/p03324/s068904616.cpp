#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
int main(void){
   int D,N;
   cin>>D>>N;
   int ans=0;
   rep(i,N){
       ans+=pow(100,D);
   }
   if(N==100){
           ans+=pow(100,D);
       }
   cout<<ans<<endl;
}