#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=1000000007;
const double PI=3.14159265358979;
const ll INF= pow(10,18);
typedef pair<ll,ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

ll gcd(ll n,ll m){
  if(n%m==0){
    return m;
  }
  else
    return gcd(m,n%m);
}

int main() {
  ll n,m;
  string s,t;
  cin >> n >> m >> s >> t;
  ll L=n*m/gcd(n,m);
  ll ans=L;
  ll k=gcd(n,m);
  bool a=true;
  rep(i,k){
    if(s[i*n/k]!=t[i*m/k]){
      a=false;
    }
  }
  if(a){
    cout << ans << endl;
  }
  else
    cout << -1 << endl;
}