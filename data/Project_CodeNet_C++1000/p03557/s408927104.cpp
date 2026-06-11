#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  vector<ll> b(n);
  vector<ll> c(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];
  rep(i, n) cin >> c[i];

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  sort(c.begin(), c.end());

  // あるbの段を選んだときにcの段がいくつ選べるか
  vector<ll> b_cnt(n);
  {
    rep(i, n) {
      auto c_it = upper_bound(c.begin(), c.end(), b[i]);
      b_cnt[i] = distance(c_it, c.end());
    }
  }
  // あるb以降の組み合わせの総和
  vector<ll> b_cnt_wa(n);
  {
    ll wa = 0;
    for(int i=n-1;i>=0;i--) {
      wa += b_cnt[i];
      b_cnt_wa[i] = wa;
    }
  }

  // あるaの段を選んだとき
  ll ans = 0;
  {
    rep(i, n) {
      auto b_it = upper_bound(b.begin(), b.end(), a[i]);
      int b_index = distance(b.begin(), b_it);
      ans += b_cnt_wa[b_index];
    }
  }
  cout << ans << endl;
  return 0;
}
