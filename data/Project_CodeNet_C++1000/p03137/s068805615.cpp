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
const lint inf=1e9+7;
const int MOD=1000000007;

signed main(){
  int n,m;cin>>n>>m;
  vector<int> x(m);
  vector<int> sub(m-1);
  rep(i,m)cin>>x[i];
  sort(x.begin(),x.end());
  rep(i,m-1)sub[i]=x[i+1]-x[i];
  sort(sub.begin(),sub.end());
  int res=0;
  rep(i,m-n){
      res+=sub[i];
      //cout<<res<<"\n";
  }
  cout<<res<<"\n";
  return 0;
}