#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll N;
  cin >> N;
  vector<ll> delt(N);
  ll c = 0;
  ll dec = 0; 
  
  for (ll &e : delt) cin >> e;
  for (ll i = 0; i < N; i++) {
    ll x;
    cin >> x;
    delt[i] -= x;
    if (delt[i] < 0) {
      dec += delt[i];
      c += 1;
    }
  }
  
  sort(delt.begin(), delt.end(), greater<ll>());
  for (int i = 0; i < N; i++) {
    if (delt[i] <= 0) {
      cout << -1 << endl;
      return 0;
    }
    c += 1;
    dec += delt[i];
    if (dec >= 0) {
      if (c == 1) c--;
      cout << c << endl;
      return 0;
    }
  }
}