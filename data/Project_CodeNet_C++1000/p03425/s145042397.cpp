#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

const vector<char> C = {'M', 'A', 'R', 'C', 'H'};

int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; i++) cin >> s[i];

  map<char, ll> m;
  for (auto c : C) m[c] = 0;

  for (int i = 0; i < n; i++) {
    bool ok = false;
    for (auto c : C) {
      if (s[i][0] == c) m[c]++;
    }
  }

  ll ans = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = i + 1; j < 5; j++) {
      for (int k = j + 1; k < 5; k++) {
        ans += m[C[i]] * m[C[j]] * m[C[k]];
      }
    }
  }
  cout << ans << endl;
}
