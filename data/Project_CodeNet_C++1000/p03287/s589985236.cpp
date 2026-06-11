#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll N, M;
  cin >> N >> M;
  map<ll, ll> dict;
  dict.insert(make_pair(0, 1));
  ll sum = 0;
  for (ll i = 0; i < N; ++i) {
    ll ai;
    cin >> ai;
    sum += ai;
    ll mod = sum % M;
    if (dict.find(mod) == dict.end()) {
      dict.insert(make_pair(mod, 1));
    } else {
      ++dict.at(mod);
    }
  }
  ll result = 0;
  for (auto iter = dict.begin(); iter != dict.end(); ++iter) {
    ll cnt = iter->second;
    result += (cnt * (cnt - 1)) / 2;
  }
  cout << result << endl;
  
  return 0;
}