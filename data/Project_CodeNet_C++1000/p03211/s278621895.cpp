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
  string s;cin>>s;
  int res=inf;
  int cur=(s[0]-'0')*100+(s[1]-'0')*10+s[2]-'0';
  int n=s.length();
  res=min(res,abs(753-cur));
  rep(i,n){
      if(i<3)continue;
      cur%=100;cur*=10;
      cur+=s[i]-'0';
      res=min(res,abs(753-cur));
  }
  cout<<res<<"\n";
  return 0;
}