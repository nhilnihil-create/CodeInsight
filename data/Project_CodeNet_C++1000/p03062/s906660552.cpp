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
  LL zero,a,b,c,d,e,n,m,l,k,r,x,y,z,odd,ans=0,ans2=0,h,w;
string s,S,t;
int main() {
ios_base::sync_with_stdio(false);
cin >>n;
odd=0;
vector<LL> A(n);
REP(i,n){
    cin>> a;
    if(a<0)odd++;
    else if(a==0)zero++;
   A[i] =abs(a);
}
SORT(A);
if(odd%2==0){
 REP(i,n)ans+=A[i];
cout << ans;
return 0;
}else if(zero>=1){
  REP(i,n)ans+=A[i];
cout << ans;
return 0;
}else{
    A[0]*=-1;
  REP(i,n)ans+=A[i];
    cout << ans;
    return 0;
}
}
