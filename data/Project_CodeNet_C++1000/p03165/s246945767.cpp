#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN = 3e3 + 10;

char s[maxN], t[maxN];
int f[maxN][maxN];

void Trace(int i, int j) {
  if (i == 0 || j == 0) return;
  while (i > 1 && f[i][j] == f[i-1][j]) {
    --i;
  }
  while (j > 1 && f[i][j] == f[i][j-1]) {
    --j;
  }
  Trace(i-1, j-1);
  if (s[i] == t[j]) cout << s[i];
}
int main(){
//  freopen("abc.inp", "r", stdin); freopen("abc.out", "w", stdout);
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> s + 1;
  cin >> t + 1;
  int n = strlen(s+1), m = strlen(t+1);
  for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) {
    if (s[i] == t[j]) {
      f[i][j] = f[i-1][j-1] + 1;
    } else {
      f[i][j] = max(f[i-1][j], f[i][j-1]);
    }
  }
  Trace(n, m);
return 0;
}
