#include <bits/stdc++.h>

#include <iostream>
//#include <algorithm>
// #include <iomanip>
#define ll long long
#define map unordered_map
#define set unordered_set
#define pll pair<ll, ll>
#define vll vector<ll>

using namespace std;

const ll MOD = 1000000007LL;
const ll INF = (1LL << 60LL);

string dp[10050];

ll compare(string s1, string s2) {
  if (s1.size() > s2.size()) {
    return 1;
  }

  if (s1 > s2) {
    return 1;
  }

  // for (ll i = 0; i < s1.size(); i++) {
  //   ll n1 = stoll(s1.substr(i, 1));
  //   ll n2 = stoll(s2.substr(i, 1));

  //   if (n1 > n2) {
  //     return 1;
  //   }
  //   if (n1 < n2) {
  //     return -1;
  //   }
  // }
  return 0;
}

int main() {
  for (ll i = 0; i < 10050; i++) {
    dp[i] = "";
  }

  map<ll, ll> m;
  m[1] = 2;
  m[2] = 5;
  m[3] = 5;
  m[4] = 4;
  m[5] = 5;
  m[6] = 6;
  m[7] = 3;
  m[8] = 7;
  m[9] = 6;

  ll N, M;
  scanf("%lld %lld", &N, &M);

  vector<ll> list(M);
  for (ll i = 0; i < M; i++) {
    ll v;
    scanf("%lld", &v);
    list[i] = v;
  }

  for (ll i = 0; i < N; i++) {
    for (ll j = 0; j < list.size(); j++) {
      if (dp[i].size() == 0 && i > 0) {
        continue;
      }

      ll n = list[j];
      ll required = m[n];

      // cout << "required:" << required << endl;

      string new_ch = to_string(n);

      // cout << "new_ch:" << new_ch << endl;
      string new_string = dp[i] + new_ch;

      // cout << "new_string:" << new_string << endl;

      if (compare(new_string, dp[i + required]) == 1) {
        dp[i + required] = new_string;
        // cout << i << "->" << i + required << ":" << new_string << endl;
      }
    }
  }

  // for (ll i = 0; i <= N; i++) {
  //   cout << i << ":" << dp[i] << endl;
  // }
  cout << dp[N] << endl;
}
