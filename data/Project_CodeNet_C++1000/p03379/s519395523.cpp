#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
int n, x[200010], y[200010];
int main() {
  cin >> n;
  rep(i,n) {
    cin >> x[i];
    y[i] = x[i];
  }
  sort(y,y+n);
  int l = y[n/2-1], r = y[n/2];
  rep(i,n) {
    if (x[i] <= l) cout << r << endl;
    else if (x[i] >= r) cout << l << endl;
  }

  return 0;
}