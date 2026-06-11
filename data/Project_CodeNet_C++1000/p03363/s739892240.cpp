#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  for (ll i = 0; i < N; i++) {
    ll x;
    cin >> x;
    if (i == 0) A[i] = x;
    else A[i] = A[i-1] + x;
  }
  map<ll,ll> mp;
  for (auto e : A) mp[e] += 1;
  mp[0] += 1;
  ll ans = 0;
  for (auto m : mp) {
    ll q = m.second;
    ans += q*(q-1)/2;
  }
  cout << ans << endl;
}