#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cmath>
#include<cstdio>
#include<tuple>
#include<bitset>
#include<map>

using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
using ll = long long;
using lint = long long;
typedef pair<int,int> P;
const lint inf=1e18+7;
const int MOD=1000000007;
signed main(){
  int n,k;cin>>n>>k;
  vector<int> h(n);
  rep(i,n)cin>>h[i];
  sort(h.begin(),h.end());
  lint res=inf;
  rep(i,n){
      if(i+k-1==n)break;
      res=min(res,h[i+k-1]-h[i]);
  }
  cout<<res<<"\n";
  return 0;
}