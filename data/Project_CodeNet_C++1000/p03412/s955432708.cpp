#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5;

int s[30];
int a[2][30][N];
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n; cin >> n;

  for(int k = 0; k < 2; k++) {
    for(int i = 0; i < n; i++) {
      int x; cin >> x;
      int t = 0;
      for(int j = 0; j < 30; j++) {
        t |= x & (1 << j);
        a[k][j][i] = t;
        if((!!(x & (1 << j))) & (n & 1)) s[j] ^= 1;
      }
    }
  }

  for(int j = 0; j < 29; j++) {
    sort(a[1][j], a[1][j] + n);
    for(int i = 0; i < n; i++) {
      int p = lower_bound(a[1][j], a[1][j] + n, (1 << (j + 1)) - a[0][j][i]) - a[1][j];
      s[j + 1] ^= (n - p) & 1;
    }
  }

  int ans = 0;
  for(int i = 29; i >= 0; i--) (ans <<= 1) |= s[i];
  cout << ans << endl;
}
