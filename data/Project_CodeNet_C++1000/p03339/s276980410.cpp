#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
int main() {
  int n, e = 0;
  string s;
  cin >> n >> s;
  int a[2][n + 1];
  a[0][0] = 0;
  a[1][0] = 0;
  rep(i,n)
  {
    if (s[i] == 'W') {
      a[0][i + 1] = a[0][i] + 1;
      a[1][i] = a[1][i > 0 ? i - 1 : 0];
    } else {
      a[0][i + 1] = a[0][i];
      a[1][i] = a[1][i > 0 ? i - 1 : 0] - 1;
      e++;
    }
  }
  int ans = n;
  rep(i,n)
  {
    ans = min(ans, a[0][i] + a[1][i] + e);
  }
  cout <<ans;
}