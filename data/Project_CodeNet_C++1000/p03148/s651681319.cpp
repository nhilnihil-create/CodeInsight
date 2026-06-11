#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N; cin >> N;
  int K; cin >> K;
  vector<pair<ll, int>> dt(N);
  for (int i = 0; i < N; i++) {
    int t; ll d;
    cin >> t >> d;
    t--;
    dt[i] = make_pair(d, t);
  }
  sort(dt.begin(), dt.end());
  reverse(dt.begin(), dt.end());

  ll ans = 0;
  ll x = 0;
  vector<int> cnt(N, 0);
  for (int i = 0; i < K; i++) {
    pair<ll, int> p = dt[i];
    ans += p.first;
    cnt[p.second]++;

    if (cnt[p.second] == 1) {
      x++;
    }
  }
  ans += x * x;

  int l = K, r = K - 1;
  ll temp = ans;
  while (true) {
    pair<ll, int> p;
    while (true) {
      l--;
      if (l < 0) break;
      p = dt[l];
      if (cnt[p.second] > 1) {
        temp -= p.first;
        cnt[p.second]--;
        break;
      }
    }
    while (true) {
      r++;
      if (r >= N) break;
      p = dt[r];
      if (cnt[p.second] == 0) {
        temp += p.first;
        cnt[p.second]++;
        break;
      }
    }

    if (l < 0 || r >= N) break;
    temp -= x * x;
    x++;
    temp += x * x;
    ans = max(ans, temp);
  }
  cout << ans << '\n';
  return 0;
}