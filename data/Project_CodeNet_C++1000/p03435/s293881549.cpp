#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1001001001
#define LINF 1001001001001001001
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define bit(n) (1LL<<(n))
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> LLP;

int main() {
  
  vector c(3, vector<int>(3));
  rep(i,3) rep(j,3) cin >> c[i][j];

  rep(k,101) {
    int a[3], b[3];
    a[0] = k;
    rep(j,3) b[j] = c[0][j] - a[0];
    a[1] = c[1][0] - b[0];
    a[2] = c[2][0] - b[0];

    bool flag = true;
    rep(i,3) rep(j,3) {
      if (a[i] + b[j] != c[i][j]) flag = false;
    }
    if (flag) {
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;

  return 0;
}