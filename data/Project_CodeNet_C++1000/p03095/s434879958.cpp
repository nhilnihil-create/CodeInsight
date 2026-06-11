#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> cnt(26);
  for (char c : s) {
    ++cnt[c - 'a'];
  }
  int res = 1;
  const int md = 1e9 + 7;
  for (int i = 0; i < 26; i++) {
    res = (long long) res * (cnt[i] + 1) % md;
  }
  cout << (res + md - 1) % md << '\n';
  return 0;
}