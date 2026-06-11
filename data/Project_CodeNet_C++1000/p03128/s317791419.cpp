#include <bits/stdc++.h>
using namespace std;

int table[] = {
  0, 2, 5, 5, 4, 5, 6, 3, 7, 6
};

int n, m;
int a[10];
bool dp[10001][10001];
char dig[10001][10001];
int main() {
  cin >> n >> m;
  for (int p = 0; p < m; ++p) {
    cin >> a[p];
  }
  sort(a, a + m);
  
  dp[0][0] = true;
  for (int i = 1; i <= n; ++i) {
    for (int k = 1; k <= n; ++k) {
      for (int p = m - 1; p >= 0; --p) {
        int d = a[p];
        int c = table[d];
        if (k - c < 0) continue;
        if (dp[i - 1][k - c]) {
          dp[i][k] = true;
          dig[i][k] = d;
          break;
        }
      }
    }
  }
  
  string ans;
  int i = n;
  while (!dp[i][n]) {
    --i;
  }
  
  int k = n;
  for (; i > 0; --i) {
    int d = dig[i][k];
    int c = table[d];
    ans += '0' + d;
    k -= c;
  }
  cout << ans << endl;
}