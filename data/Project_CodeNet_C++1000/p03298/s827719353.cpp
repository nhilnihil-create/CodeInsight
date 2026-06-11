#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

int main() {
  ll N;
  cin >> N;

  string S;
  cin >> S;

  string s1 = S.substr(0, N);
  string s2 = S.substr(N, 2 * N);
  reverse(s2.begin(), s2.end());

  unordered_map<string, ll> m1, m2;
  for (ll i = 0; i < (1ll << N); i++) {
    pair<string, string> p1, p2;

    for (ll j = 0; j < N; j++) {
      if (i & (1ll << j)) {
        p1.first += s1[j];
        p2.first += s2[j];
      } else {
        p1.second += s1[j];
        p2.second += s2[j];
      }
    }


    m1[p1.first + "," + p1.second] += 1;
    m2[p2.first + "," + p2.second] += 1;
  }

  ll ans = 0;
  for (auto p: m1) {
    ans += p.second * m2[p.first];
  }

  cout << ans << endl;
}
