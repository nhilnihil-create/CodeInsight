#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define REP(i, n) for (LL i = 0; i < (LL)(n); i++)
#define REP2(i, n) for (LL i = 1; i <= (LL)(n); i++)
#define FOR(i, m, n) for (LL i = m; i < n; i++)
#define SORT(x) sort(x.begin(), x.end())
#define REVE(x) reverse(x.begin(), x.end())
#define ALL(x) (x).begin(), (x).end()
#define SUM(x) accumulate(x.begin(), x.end(),0)
#define vLL(v,n) vector<LL> v(n); REP(i,n)cin>>v[i];
#define vstr(v,n) vector<string> v(n); REP(i,n)REP(i,n)cin>>v[i];
LL INF = 1e9 + 1;
LL MOD = 1e9+7;
  LL a,b,c,d,e,n,m,l,k,r,x,y,z,ans=INF,ans2=0,h,w;
string s,S,t;
int main() {
ios_base::sync_with_stdio(false);
cin >>n>>k;
vLL(X,n);
	for (LL i = 0;i < n - k + 1;++i) {
		LL l = X[i];
		LL r = X[i + k - 1];
		LL m = min(abs(l), abs(r)) + abs(l - r);
		ans = min(ans, m);
	}
  cout <<ans<<endl;
  return 0;
}