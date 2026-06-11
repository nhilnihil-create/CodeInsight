#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (ll i = 0; i < (n); i++)
typedef pair<ll,ll> P;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}


int main(){

  ll n,m,c;
  cin >> n >> m >> c;
  vector<ll> b(m);
  rep(i,m) cin >> b[i];

  ll ans = 0;
  rep(i,n){
    ll sum = 0;
    rep(j,m){
      ll a; cin >> a;
      sum += a*b[j];
    }
    sum += c;
    if(sum > 0){
      ans ++;
    }
  }

  cout << ans << endl;

  return 0;
} 