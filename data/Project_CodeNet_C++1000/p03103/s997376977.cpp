#include <bits/stdc++.h>
#include<iostream>
#include<cmath>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll=long long;
using P=pair<int,int>;
const int INF=1001001001;


int main(){
   int n,m; cin>>n>>m;
   vector<int> a(n),b(n);
   rep(i,n) cin>>a[i]>>b[i];
   vector<pair<int,int>> pa(n);
   rep(i,n) pa[i]=make_pair(a[i],b[i]);
   sort(pa.begin(),pa.end());

   ll ans=0;
   rep(i,n){
      int buy=min(m,pa[i].second);
      ans+=(ll)buy*pa[i].first;
      m-=buy;
   }
   cout<<ans<<endl;
   return 0;
}
