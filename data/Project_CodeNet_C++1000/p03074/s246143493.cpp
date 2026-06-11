#include <bits/stdc++.h>

#include <iostream>
//#include <algorithm>
// #include <iomanip>
#define ll long long
// #define map unordered_map
// #define set unordered_set

using namespace std;

const ll MOD = 1000000007;
const ll INF = (1LL << 62);

int main() {
  ll N, K;
  scanf("%lld %lld", &N, &K);

  string s;
  cin >> s;

  // map<ll, ll> m;

  // ll start1_index = -1;
  // for (ll i = 0; i < s.size(); i++) {
  //   char ch = s[i];

  //   if (ch == '0') {
  //     if (start1_index >= 0) {
  //       m[start1_index] = i - start1_index;
  //       start1_index = -1;
  //     } else {
  //     }
  //   } else {
  //     if (start1_index >= 0) {
  //     } else {
  //       start1_index = i;
  //     }
  //   }
  // }

  // if (!(m.find(0) != m.end())) {
  //   m[-1] = 0;
  // }
  // if (s[s.size() - 1] == '1') {
  //   m[start1_index] = s.size() - start1_index;
  // } else {
  //   m[s.size()] = 0;
  // }

  // auto ite = m.begin();

  // for (; ite != end(m); ite++) {
  //   cout << (*ite).first << "," << (*ite).second << endl;
  // }

  vector<pair<ll, ll>> list;

  if (s[0] == '0') {
    list.emplace_back(make_pair(0, 0));
  }

  ll start1_index = -1;
  for (ll i = 0; i < s.size(); i++) {
    char ch = s[i];

    if (ch == '0') {
      if (start1_index >= 0) {
        ll len = i - start1_index;
        list.emplace_back(make_pair(start1_index, len));
        start1_index = -1;
      } else {
      }
    } else {
      if (start1_index >= 0) {
      } else {
        start1_index = i;
      }
    }
  }

  if (s[s.size() - 1] == '1') {
    ll len = s.size() - start1_index;
    list.emplace_back(make_pair(start1_index, len));
  } else {
    list.emplace_back(make_pair(s.size(), 0));
  }

  // for (ll i = 0; i < list.size(); i++) {
  //   cout << list[i].first << "," << list[i].second << endl;
  // }

  ll ans = 0;

  for (ll i = 0; i < list.size(); i++) {
    ll start_index = list[i].first;

    ll index2 = min((ll)(list.size() - 1), i + K);

    ll end_index = list[index2].first;

    ll length = (end_index - start_index) + list[index2].second;

    ans = max(ans, length);
  }

  cout << ans << endl;
}

// 11101010110011

// 0,3
// 4,1
// 6,1
// 8,2
// 12,2
