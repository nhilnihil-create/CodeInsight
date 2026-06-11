#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  ll n, res = 1;
  string s;
  cin >> n >> s;
  ll num[30]={};

  for (auto c : s) num[c - 'a']++;
  for (int i = 0; i < 26; ++i) {
    res *= num[i] + 1;
    res %= MOD;
  }

  cout << res - 1 << endl;
  return 0;
}
