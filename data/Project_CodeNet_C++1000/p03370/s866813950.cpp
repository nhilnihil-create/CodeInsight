#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
int main(void){
   int N,X,m;
   cin>>N>>X;
   
   int minD=1001;
   rep(i,N){
       cin>>m;
       X-=m;
       minD=min(minD,m);
   }
   int ans=N+X/minD;
   cout<<ans<<endl;
}