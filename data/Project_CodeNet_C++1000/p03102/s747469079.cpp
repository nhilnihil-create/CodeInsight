#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
using namespace std;
using ll = long long;
using P = pair<int, int>;
const ll N = pow(10, 9);
 
int main() {
  int n,m,c;
  int ans = 0;
  cin >> n >> m >> c;
  vector<int> b(m);
  rep(i,m) cin >> b[i];
  rep(i,n) {
    int A = 0;
    rep(j,m) {
      int a;
      cin >> a;
      A += a*b[j];
    }
    if (A + c > 0) ans++;
  }
  cout << ans << endl;
  return 0;
}