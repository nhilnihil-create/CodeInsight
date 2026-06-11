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
  int n,m;cin>>n>>m;
  lint res=0;
  vector<P> a(n);
  rep(i,n)cin>>a[i].first>>a[i].second;
  sort(a.begin(),a.end());
  int cur=0;
  rep(i,m){
      if(a[cur].second==0)++cur;
      a[cur].second-=1;
      res+=a[cur].first;
  }
  cout<<res<<"\n";
  return 0;
}