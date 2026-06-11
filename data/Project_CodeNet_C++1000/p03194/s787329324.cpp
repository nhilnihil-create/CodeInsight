#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const ll M = 1e9 + 7;

int main() {
  ll n, p;
  cin >> n >> p;

  if (n==1){
    cout << p << endl;
    return 0;
  }

  vector<ll> v(1e6+1,0);
  v[1] = n;
  for (ll i = 2; i*i <= p; i++){
    while(p%i == 0){
      v[i]++;
      p /= i;
    }
  }

  ll ans = 1;
  for(ll i = 0; i <= v.size(); i++){
    ans *= powl((i+1),(ll)(v[i+1]/n));
  }

  cout << ans << endl;

  return 0;
}
