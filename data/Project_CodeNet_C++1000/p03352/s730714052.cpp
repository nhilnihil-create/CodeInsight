#include <bits/stdc++.h>
#include<iostream>
#include<cmath>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll=long long;
using P=pair<int,int>;
const int INF=1001001001;

int main(){
   int x; cin>>x;
   int a;
   int maxr=0;
   if(x==1){
      cout<<1<<endl;
      return 0;
   }
   for(int i=2;i<=x;i++){
      int j=2;
      int ans=i;
      if(ans*ans<=x){
         while(ans*i<=x){
            ans*=i;
            //cout<<ans<<" ";
         }
         //cout<<endl;
         //cout<<ans<<endl;
         maxr=max(maxr,ans);
      }
   }
   cout<<maxr<<endl;
   return 0;
}
