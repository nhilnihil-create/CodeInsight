#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, q;
  cin >> n >> q;
  string s ;
  cin >> s;
  vector<int> dp(n+1);
  for (int i = 0; i < n; i++) {
    int tmp;
    if (s.substr(i,2)=="AC") tmp = 1;
    else tmp = 0;
    dp[i+1] = dp[i] + tmp;
  }

  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    cout << dp[r-1] - dp[l-1] << endl;;
  }
  return 0;
}