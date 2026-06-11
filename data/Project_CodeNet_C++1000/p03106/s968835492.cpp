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
 LL a,b,c,d,e,n,m,l,k,r,x,y,z,ans=0,ans2=0,cnt=0;
string s,S,t;
int main() {
ios_base::sync_with_stdio(false);
  cin >> a>>b>>k;
 for ( int i = min (a , b ); i >= 1; --i ) {
      if(a%i==0&&b%i==0){
          --k ;
        if(0==k){
            cout <<i<<endl;
            return 0;
        }
      }
  }
}