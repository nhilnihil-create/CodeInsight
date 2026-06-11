#include <bits/stdc++.h>
#define INF 100000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

int main()
{
  ll N;
  cin >> N;
  vector<ll> A(N);
  for (ll i = 0; i < N; ++i) {
    cin >> A.at(i);
  }
  sort(A.begin(), A.end());
  unordered_map<ll, ll> mp;
  ll ans = 0;
  for (ll i = 0; i < N; ++i) {
    mp[A.at(i)] += 1;
  }
  for (ll i = N - 1; i >= 0; --i) {
    if (mp[A.at(i)] == 0) {
      continue;
    }
    mp[A.at(i)] -= 1;
    ll pow2 = 1;
    while (pow2 <= A.at(i)) {
      pow2 *= 2;
    }
    ll need = pow2 - A.at(i);
    // cout << "need" << need << endl;
    if (mp[need] != 0) {
      mp[need] -= 1;
      ans += 1;
    }
    else {
      mp.erase(need);
    }
  }
  cout << ans << endl;
}
