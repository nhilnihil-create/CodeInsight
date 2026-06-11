#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<double, int>;

double n, t, a;

int main() {
  cin >> n >> t >> a;
  vector<int> h(n);
  rep (i, n) {
    cin >> h[i];
  }
  vector<P> v(n);
  rep (i, n) {
    v[i] = make_pair(abs(a - t + 0.006 * h[i]), i+1);
  }
  sort(v.begin(), v.end());
  cout << v[0].second << endl;
  return 0;
}
