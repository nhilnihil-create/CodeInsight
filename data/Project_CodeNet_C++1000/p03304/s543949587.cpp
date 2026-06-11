#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cmath>
#include<cstdio>
#include<tuple>
#include<bitset>

using namespace std;
//#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
#define ll long long
const int inf=1000000007;
const int MOD=1000000007;
signed main(){
  double n,m,d;
  cin>>n>>m>>d;
  printf("%lf\n",(double)(2-(int)(d==0))*(n-d)*(m-(double)1)/n/n);
  return 0;
}
