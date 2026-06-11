#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const ll INF = 1LL<<60;

int main()
{
  int N;
  int t[110000], x[110000], y[110000];
  cin >> N;
  rep(i, N) {
    cin >> t[i+1] >> x[i+1] >> y[i+1];
  }

  bool can = true;

  rep(i, N) {
    // 経過秒数
    int dt = t[i+1] - t[i];

    int dist = abs(x[i+1] - x[i]) + abs(y[i+1] - y[i]);
    if (dt < dist) can = false;
    if (dist % 2 != dt % 2) can = false;
  }

  if (can) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}