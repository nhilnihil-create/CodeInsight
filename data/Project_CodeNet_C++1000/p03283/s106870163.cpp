#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 25;
const int MOD = 1e9+7;

int train[500][500];
int sum[501][501]; 
int main() {
  int n,m,q;
  cin >> n >> m >> q;
  int l, r;
  rep(i,m) {
    cin >> l >> r;
    l--; r--;
    train[l][r]++;
  }

  rep(i,n) rep(j,n) {
    sum[i+1][j+1]=sum[i+1][j]+sum[i][j+1]-sum[i][j]+train[i][j];
  }

  int x,y;
  rep(i,q) {
    cin >> x >> y; x--;
    int now = sum[y][y]-sum[x][y]-sum[y][x]+sum[x][x];
    cout << now << endl;
  }
  return 0;
}