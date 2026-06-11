#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string s;
  cin >> s;
  vector<int> cnt(3, 0), ans(3, 1);
  for (int i = 0; i < 3; i++) cnt[s[i]-'a']++;
  if (cnt == ans) cout << "Yes" << endl;
  else cout << "No" << endl;
}
