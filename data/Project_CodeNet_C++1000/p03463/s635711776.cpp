#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops")
using namespace std;
#define ll long long
#define FOR(i,a,b) for (int i = (a); i<(b); i++)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,n+1)
#define RREP(i,n) for (int i=(n)-1; i>=0; i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)(x.size())
#define SQ(x) (x)*(x)
#define pii pair<int, int>
#define endl '\n'
//#define TOAD
//#define int ll
#ifdef TOAD
#define bug(x) cerr<<__LINE__<<": "<<#x<<" is "<<x<<endl
#define IOS() 
#else
#define bug(...)
#define IOS() ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
const ll inf = 1ll<<60;
const int iinf=2147483647;
const ll mod = 998244353;
const ll maxn=300005;
ll pow(ll a, ll b){
  ll re=1;
  while(b){
    if (b&1){
      re*=a;
      re%=mod;
    }
    a*=a;
    a%=mod;
    b>>=1;
  }
  return re;
  //ㄑ 
}
ll mul2(ll a,ll b,ll n){
    a%=n,b%=n;
    ll y=(ll)((long double)a*b/n+0.5); 
    ll r=(a*b-y*n)%n;
    return r<0?r+n:r;
}
 
signed main (){
  IOS();
  int a, b, c; cin>>a>>b>>c;
  if ((c-b)%2==0) cout<<"Alice\n";
  else cout<<"Borys\n"<<endl;
 }