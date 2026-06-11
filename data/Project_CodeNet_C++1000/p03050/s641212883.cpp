#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
const int mod = 1000000007;

vector<ll> divisor(ll n) {
  vector<ll> res;
  for (ll i = 1; i * i <= n; ++i) {
    if(n % i == 0) {
      res.push_back(i);
      if(i * i != n) res.push_back(n / i);
    }
  }
  sort(res.begin(), res.end());
  return res;
}

int main(){
  ll n;
  cin >> n;
  vector<ll> div = divisor(n);
  ll ans = 0;
  rep(i, div.size()) {
    ll t = n / div[i] - 1;
    if(t == 0) continue;
    if(n % t == n / t) ans += t;

  }
  cout << ans << endl;
}