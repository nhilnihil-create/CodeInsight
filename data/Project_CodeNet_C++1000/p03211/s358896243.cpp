#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define REP(i, n) for (LL i = 0; i < (LL)(n); i++)
#define FOR(i, m, n) for (LL i = m; i < n; i++)
#define SORT(x) sort(x.begin(), x.end())
#define REVE(x) reverse(x.begin(), x.end())
#define ALL(x) (x).begin(), (x).end()
#define SUM(x) accumulate(x.begin(), x.end(),0)
#define vLL(v,n) vector<LL> v(n); REP(i,n)cin>>v[i];
#define vstr(v,n) vector<string> v(n); REP(i,n)REP(i,n)cin>>v[i];
LL INF = 1e9 + 1;
LL MOD = 1e9+7;
  LL a,b,c,d,e,n,m,l,r,ans=10000000000;
string s,S,t;
int main() {
ios_base::sync_with_stdio(false);
  cin >> s;
REP(i,s.size()-2){
ans=min(ans,llabs(753-(((LL)s[i]-48)*100+((LL)s[i+1]-48)*10+((LL)s[i+2]-48))));
}
cout <<ans<<endl;
}