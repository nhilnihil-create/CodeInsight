#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int sum = 0;
  vector<vector<int>> c(3, vector<int>(3));
  rep(i,3) rep(j,3) cin >> c[i][j];

  rep(i, c[0][0]+1) {
    vector<int> a(3), b(3);
    a[0] = i;
    b[0] = c[0][0] - i;
    rep(j, c[1][1]+1) {
      a[1] = j;
      b[1] = c[1][1] - j;
      rep(k, c[2][2]+1) {
        a[2] = k;
        b[2] = c[2][2] - k;
        int cnt = 0;
        rep(l,3) {
          rep(m,3) {
            if (a[l] + b[m] != c[l][m]) break;
            else cnt++;
          }
        }
        if (cnt == 9) {
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
  }
  cout << "No" << endl;
  return 0;
}