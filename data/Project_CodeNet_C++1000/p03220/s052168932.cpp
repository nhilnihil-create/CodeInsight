#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n, t, a;
  cin >> n >> t >> a;
  vector<int> h(n);
  rep(i, n) cin >> h[i];

  int b = 0;
  for (int i = 1; i < n; ++i) if (abs(t - h[i] * 0.006 - a) < abs(t - h[b] * 0.006 - a)) b = i;
  cout << b+1 << endl;
  return 0;
}