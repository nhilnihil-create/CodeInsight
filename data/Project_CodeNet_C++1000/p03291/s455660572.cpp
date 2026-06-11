#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin>>s;
  int n = s.length();
  long long dp_a[n+1][4];
  long long mod = 1e9 + 7;

  for (int i=0; i<4; i++) {
    dp_a[0][i] = 0;
  }
  for (int i=0; i<n; i++) {
    dp_a[i+1][0] = dp_a[i][0];
    dp_a[i+1][1] = dp_a[i][1];
    dp_a[i+1][2] = dp_a[i][2];
    dp_a[i+1][3] = dp_a[i][3];
    if (s[i] == 'A') {
      dp_a[i+1][0] = dp_a[i][0] + 1;
    } else if (s[i] == '?') {
      dp_a[i+1][1] = dp_a[i][1] + 1;
    }
  }
  long long dp_ab[n+1][4];
  for (int i=0; i<4; i++) {
    dp_ab[0][i] = dp_ab[1][i] = 0;
  }
  for (int i=0; i<n-1; i++) {
    dp_ab[i+2][0] = dp_ab[i+1][0];
    dp_ab[i+2][1] = dp_ab[i+1][1];
    dp_ab[i+2][2] = dp_ab[i+1][2];
    dp_ab[i+2][3] = dp_ab[i+1][3];

    if (s[i+1] == 'B') {
      dp_ab[i+2][0] += dp_a[i+1][0];
      dp_ab[i+2][1] += dp_a[i+1][1];
    } else if (s[i+1] == '?') {
      dp_ab[i+2][1] += dp_a[i+1][0];
      dp_ab[i+2][2] += dp_a[i+1][1];
    }
  }

  long long dp_abc[n+1][4];
  for (int i=0; i<4; i++) {
    dp_abc[0][i] = dp_abc[1][i] = dp_abc[2][i] = 0;
  }
  for (int i=0; i<n-2; i++) {
    dp_abc[i+3][0] = dp_abc[i+2][0];
    dp_abc[i+3][1] = dp_abc[i+2][1];
    dp_abc[i+3][2] = dp_abc[i+2][2];
    dp_abc[i+3][3] = dp_abc[i+2][3];
    if (s[i+2] == 'C') {
      dp_abc[i+3][0] += dp_ab[i+2][0];
      dp_abc[i+3][1] += dp_ab[i+2][1];
      dp_abc[i+3][2] += dp_ab[i+2][2];
    } else if (s[i+2] == '?') {
      dp_abc[i+3][1] += dp_ab[i+2][0];
      dp_abc[i+3][2] += dp_ab[i+2][1];
      dp_abc[i+3][3] += dp_ab[i+2][2];
    }
    dp_abc[i+3][0] %= mod;
    dp_abc[i+3][1] %= mod;
    dp_abc[i+3][2] %= mod;
    dp_abc[i+3][3] %= mod;
  }
  int n_qmark = 0;
  for (int i=0; i<n; i++) {
    if (s[i] == '?') {
      ++n_qmark;
    }
  }
  long long ans = 0;
  for (int i=0; i<4; i++) {
    if (n_qmark < i) {
      break;
    }
    long long x = 1;
    for (int j=0; j<n_qmark-i; j++) {
      x *= 3;
      x %= mod;
    }
    ans += x * dp_abc[n][i];
    ans %= mod;
  }
  cout<<ans<<endl;
}