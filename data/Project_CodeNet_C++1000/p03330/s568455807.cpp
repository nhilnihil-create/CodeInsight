#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n, c;
  cin >> n >> c;
  vector< vector< int > > d(c, vector< int >(c));
  vector< vector< int > > m(n, vector< int >(n));
  for (int i=0; i<c; ++i) {
    for (int j=0; j<c; ++j) cin >> d[i][j];
  }
  for (int i=0; i<n; ++i) {
    for (int j=0; j<n; ++j) cin >> m[i][j];
  }
  vector< vector< int > > a(3, vector< int >(c, 0));
  for (int i=0; i<n; ++i) {
    for (int j=0; j<n; ++j) {
      for (int k=0; k<c; ++k) a[(i+j)%3][k] += d[m[i][j]-1][k];
    }
  }
  int ans = a[0][0] + a[1][1] + a[2][2];
  for (int i=0; i<c; ++i) {
    for (int j=0; j<c; ++j) {
      for (int k=0; k<c; ++k) {
        if (i==j || j==k || k==i) continue;
        ans = min(ans, a[0][i] + a[1][j] + a[2][k]);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
