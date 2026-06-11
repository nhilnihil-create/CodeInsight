#include <bits/stdc++.h>
#include <random>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,n) for (int i = 1; i <= (n); ++i)
#define P(a,b) make_pair(a,b)

using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using ull= unsigned long long;
const ll K_MAX=1e5+5;
const ll Lmax=ll(1e18);
const int Nmax=2e5+1;
const int Nd=61;
const int INF=1e5;
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;} //最大公約数
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;} //最小公倍数


int main(){
  ll n,m;
  string s,t;
  cin>>n>>m>>s>>t;
  ll x=lcm(n,m);


  ll n0=n/gcd(n,m),m0=m/gcd(n,m);

  rep(i,gcd(n,m)){
    ll a=i*n0;
    ll b=i*m0;
    if(s[a]!=t[b]){
      cout<<-1<<endl;
      return 0;
    }
  }

  cout<<x<<endl;
  return 0;





  return 0;
}
