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
  LL a,b,c,d,e,n,m,l,r,x,y,z,ans=0,ans2=0,count;
string s,S,t;
int main() {
ios_base::sync_with_stdio(false);
cin >> n>>a>>b;
for(int i = 1 ; i <= n ; i++)
{
  c=0;
int t = i ; 
for (int j = 0 ; j < 5 ; j++)c += t % 10 , t /= 10;
if( a <= c&&c <= b ) ans += i ;
}
  cout << ans;
}