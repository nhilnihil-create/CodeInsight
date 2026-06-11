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
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
#define ll long long
using lint=long long;
typedef pair<int,int> P;
const int inf=1000000007;
const int MOD=1000000007;
signed main(){
  int n,x,y;cin>>n>>x>>y;
  vector<int> a(n+1,0);
  rep1(i,n)cin>>a[i];
  a[0]=a[n];
  int res=abs(a[n-1]-a[n]);
  res=max(res,abs(a[n]-y));
  cout<<res<<"\n";
  return 0;
}