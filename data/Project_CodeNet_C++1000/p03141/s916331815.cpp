#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;
  vector<pair<ll, ll>> vab(n);
  for (int i = 0; i < n; ++i) {
    cin >> vab[i].first >> vab[i].second;
  }

  sort(vab.begin(), vab.end(), [](auto &a, auto &b) {
    return a.first + a.second > b.first + b.second;
  });

  ll a_sum = 0, b_sum = 0;
  for (int i = 0; i < n; ++i) {
    if (i % 2 == 0) {
      a_sum += vab[i].first;
    } else {
      b_sum += vab[i].second;
    }
  }

  cout << a_sum - b_sum << '\n';
}