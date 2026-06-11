#include <bits/stdc++.h>

using namespace std;

const int N = 20;
const int md = (int) 1e9 + 9;
const int pr[] = {37, 1999};

inline pair<int, int> get(string s) {
  int res[2] = {0, 0};
  for (char c : s) {
    for (int it : {0, 1}) {
      res[it] = 1LL * res[it] * pr[it] % md;
      res[it] += c - 'a';
      if (res[it] >= md) res[it] -= md;
    }
  }
  return {res[0], res[1]};
}

map<pair<int, int>, int> cnt[N];

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int m = (int) s.size();
  for (int mask = 0; mask < (1 << n); mask++) {
    string sc, tc;
    for (int i = 0; i < n; i++) {
      if ((mask >> i) & 1) {
        tc = s[i] + tc;
      } else {
        sc += s[i];
      }
    }
    ++cnt[(int) sc.size()][get(sc + tc)];
  }
  long long res = 0;
  for (int mask = 0; mask < (1 << n); mask++) {
    string sc, tc;
    for (int i = 0; i < n; i++) {
      if ((mask >> i) & 1) {
        tc = s[i + n] + tc;
      } else {
        sc += s[i + n];
      }
    }
    res += cnt[(int) tc.size()][get(tc + sc)];
  }
  cout << res << '\n';
  return 0;
}
