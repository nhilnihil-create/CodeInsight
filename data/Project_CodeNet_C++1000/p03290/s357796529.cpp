#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0; i<(n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
  int d, g;
  cin >> d >> g;
  vector<P> prob(d);
  rep(i,d) cin >> prob[i].first >> prob[i].second;

  ll res = 1<<29;
  rep(bit, 1<<d) {
    ll sum = 0;
    ll num = 0;
    rep(i,d) {
      if (bit & (1<<i)) {
	sum += prob[i].second + prob[i].first * 100 * (i+1);
	num += prob[i].first;
      }
    }
    if (sum >= g) res = min(res, num);
    else {
      for (int i=d-1; i>=0; --i) {
	if (bit & (1<<i)) continue;
	rep(j, prob[i].first) {
	  if (sum >= g) break;
	  sum += 100 * (i+1);
	  ++num;
	}
      }
      res = min(res, num);
    }
  }
  cout << res << endl;
  return 0;
}
