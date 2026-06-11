#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

int main() {
  int n, q;
  string s;
  cin >> n >> q >> s;
  vector<pii> sec(q);
  for (auto&& e : sec) {
    int l, r;
    cin >> l >> r;
    e.first = l;
    e.second = r;
  }

  vector<int> acCount(n + 1);
  char prev = 'X';
  for (int i = 0; i < n; ++i) {
    acCount[i + 1] = acCount[i];
    if (prev == 'A' && s[i] == 'C') {
      acCount[i + 1] += 1;
    }
    prev = s[i];
  }

  for (const auto& e : sec) {
    cout << acCount[e.second] - acCount[e.first] << endl;
  }
}
