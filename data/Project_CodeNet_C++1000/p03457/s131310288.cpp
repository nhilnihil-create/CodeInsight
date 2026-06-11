#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int, int>;
typedef vector<int> vi;

int main() {
  int N;
  int t[110000], x[110000], y[110000];
  cin >> N;
  t[0] = x[0] = y[0] = 0;
  rep(i, N) cin >> t[i+1] >> x[i+1] >> y[i+1];

  bool can = true;
  rep(i, N) {
    int dt = t[i+1] - t[i];
    int dist = abs(x[i+1] - x[i]) + abs(y[i+1] - y[i]);
    if (dt < dist) can = false;
    if (dist % 2 != dt % 2) can = false;
  }

  if (can) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}