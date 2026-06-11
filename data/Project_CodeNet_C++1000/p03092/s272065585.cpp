#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
signed main(){
  Int n,a,b;
  cin>>n>>a>>b;
  vector<Int> p(n);
  for(Int i=0;i<n;i++) cin>>p[i];

  vector<Int> r(n);
  for(Int i=0;i<n;i++) r[--p[i]]=i;

  vector<Int> dp(n*2+2,0);

  const Int INF = 1e18;  
  for(Int i=0;i<n;i++){
    vector<Int> nx(n*2+2,INF);
    Int k=r[i]*2+1;
    Int tmp=INF;
    for(Int j=0;j<n*2+2;j++){      
      if(j==k) chmin(nx[j],tmp);
      chmin(tmp,dp[j]);
      if(j&1) continue;
      chmin(nx[j],tmp+(j<k?b:a));
    }
    swap(dp,nx);
  }
  
  cout<<*min_element(dp.begin(),dp.end())<<endl;
  return 0;
}
