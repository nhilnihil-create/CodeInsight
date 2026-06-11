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
  int n;cin>>n;
  vector<int> p(n);
  rep(i,n)cin>>p[i];
  sort(p.begin(),p.end());
  lint res=0;
  p[n-1]/=2;
  rep(i,n)res+=p[i];
  cout<<res<<"\n";
  return 0;
}