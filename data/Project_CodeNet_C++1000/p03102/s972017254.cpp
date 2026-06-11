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
  int n,m,c;cin>>n>>m>>c;
  int res=0;
  vector<int> b(m);
  rep(i,m)cin>>b[i];
  rep(i,n){
      int sm=c;
      rep(j,m){
          int a;cin>>a;
          sm+=a*b[j];
      }
      if(sm>0)++res;
  }
  cout<<res<<"\n";
  return 0;
}