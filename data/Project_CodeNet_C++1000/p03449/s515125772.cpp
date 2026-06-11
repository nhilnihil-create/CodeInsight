#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n; cin >> n;
  vector<int> x(n), y(n);
  int sum = 0;
  rep(i,n) {
    int a;
    cin >> a;
    sum += a;
    x[i] = sum;
  }
  sum = 0;
  rep(i,n) {
    int a;
    cin >> a;
    sum += a;
    y[i] = sum;
  }

  int ans = x[0] + y[n-1];
  for (int i = 1; i < n; i++) {
    int tmp = x[i] + y[n-1] - y[i-1];
    ans = max(ans, tmp);
  }
  cout << ans << endl;
  return 0;
}