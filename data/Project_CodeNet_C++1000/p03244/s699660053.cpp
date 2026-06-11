#include <bits/stdc++.h>

#include <iostream>
//#include <algorithm>
// #include <iomanip>
#define ll long long
#define map unordered_map
#define set unordered_set
#define l_l pair<ll, ll>
#define vll vector<ll>
#define mll map<ll, ll>

using namespace std;

const ll MOD = 1000000007LL;
const ll INF = (1LL << 60LL);

vector<l_l> calc(vector<ll> list) {
  mll m;
  for (ll i = 0; i < list.size(); i++) {
    auto v = list[i];
    m[v] += 1;
  }

  vector<l_l> r;

  auto ite = m.begin();
  for (; ite != end(m); ite++) {
    ll key = (*ite).first;
    ll val = (*ite).second;
    // cout << key << ":" << val << endl;

    r.emplace_back(make_pair(val, key));
  }

  return r;
}

int main() {
  // std::cout << std::fixed << std::setprecision(10);
  ll N;
  scanf("%lld", &N);

  vector<ll> list0;
  vector<ll> list1;
  for (ll i = 0; i < N; i++) {
    ll v;
    scanf("%lld", &v);
    if (i % 2 == 0) {
      list0.emplace_back(v);
    } else {
      list1.emplace_back(v);
    }
  }

  vector<l_l> m0 = calc(list0);
  vector<l_l> m1 = calc(list1);
  sort(m0.rbegin(), m0.rend());
  sort(m1.rbegin(), m1.rend());

  if (N == 2) {
    if (list0[0] == list1[0]) {
      cout << (1) << endl;
    } else {
      cout << (0) << endl;
    }
    return 0;
  }

  ll ans = INF;

  for (ll i0 = 0; i0 < 2; i0++) {
    if (i0 >= m0.size()) {
      continue;
    }
    for (ll i1 = 0; i1 < 2; i1++) {
      if (i1 >= m1.size()) {
        continue;
      }
      ll cnt0 = m0[i0].first;
      ll cnt1 = m1[i1].first;

      ll a;
      if (m0[i0].second == m1[i1].second) {
        a = min((N / 2 - cnt0 + N / 2), (N / 2 - cnt1 + N / 2));
      } else {
        ll change0 = N / 2 - cnt0;
        ll change1 = N / 2 - cnt1;
        a = change0 + change1;
        // cout << "a@:" << (a) << endl;
      }
      ans = min(ans, a);
      // cout << "ans:" << (ans) << endl;
    }
  }

  cout << (ans) << endl;
}
