#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<double, double> pdd;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
//const int mod = ;

int d[305][305][305];

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  string s;
  int k;
  cin >> s >> k;
  int n = s.size();
  for (int i = 0; i < n; ++i) {
    d[i][i][0] = 1;
  }
//  int res = 0;
  for (int l = 2; l <= n; ++l) {
    for (int i = 0; i + l <= n; ++i) {
      int j = i + l - 1;
      for (int t = 0; t <= k; ++t) {
        d[i][j][t] = max(d[i+1][j][t], d[i][j-1][t]);
        if (s[i] == s[j]) d[i][j][t] = max(d[i][j][t], d[i+1][j-1][t] + 2);
        if (t) {
          d[i][j][t] = max(max(d[i][j][t], d[i+1][j-1][t-1] + 2), d[i][j][t-1]);
        }
//        res = max(res, d[i][j][t]);
      }
    }
  }
  cout << max(1, d[0][n-1][k]) << endl;
  return 0;
}