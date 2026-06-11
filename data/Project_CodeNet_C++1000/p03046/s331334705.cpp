#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll M; cin >> M;
  ll K; cin >> K;

  ll MAX = 1 << M;
  if (K >= MAX) {
    cout << "-1\n";
    return 0;
  }

  if (M == 0) {
    if (K == 0) cout << "0 0\n";
    else cout << "-1\n";
    return 0;
  }

  if (M == 1) {
    if (K == 0) cout << "0 0 1 1\n";
    else cout << "-1\n";
    return 0;
  }

  deque<ll> d;
  d.emplace_back(K);
  for (int i = 0; i < MAX; i++) {
    if (i == K) continue;
    d.emplace_back(i);
    d.emplace_front(i);
  }
  d.emplace_back(K);

  for (int i = 0; i < d.size(); i++) {
    cout << d[i] << " ";
  }
  return 0;
}