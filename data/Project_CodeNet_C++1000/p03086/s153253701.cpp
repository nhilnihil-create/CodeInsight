#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string s;
  cin >> s;
  vector<bool> is_ACGT(s.size(), false);
  rep(i, s.size()) if (s[i] == 'A' || s[i] == 'C' || s[i] == 'G' || s[i] == 'T') is_ACGT[i] = true;
  int max_l = 0;
  rep(i, s.size()) for (int j = i; j < s.size(); ++j) {
    bool isOK = true;
    for (int k = i; k <= j; ++k) if (!is_ACGT[k]) isOK = false;
    if (isOK) max_l = max(max_l, j - i + 1);
  }
  cout << max_l << endl;
  return 0;
}