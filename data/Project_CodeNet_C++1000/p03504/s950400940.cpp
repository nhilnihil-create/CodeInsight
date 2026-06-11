#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 200020;

int main() {
  int n,C;
  cin >> n >> C;

  vector<int> ans(N, 0);
  vector<int> s(n), t(n), c(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i] >> t[i] >> c[i];
  }
  for (int i = 1; i <= C; i++) {
    vector<int> imos(N, 0);
    for (int j = 0; j < n; j++) {
      if(i == c[j]) imos[s[j] * 2 - 1]++, imos[t[j] * 2]--;
    }
    for (int j = 1; j < N; j++) imos[j] += imos[j - 1];
    for (int j = 0; j < N; j++) {
      if(imos[j] > 0) ans[j]++;
    }
  }

  int res = 1;
  for (auto it : ans) res = max(res, it);
  cout << res << '\n';
}