#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n, m;
  cin >> n >> m;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  vector<P> cb;
  rep(i, m) {
    int b, c;
    cin >> b >> c;
    cb.push_back({ c, b });
  }

  sort(a.begin(), a.end());
  sort(cb.begin(), cb.end(), greater<P>());

  int i = 0;
  int cb_i = 0;
  while(i < n) {
    // printf("%d: %d, %d\n", i, a[i], cb[cb_i].first);
    if(a[i] < cb[cb_i].first) {
      a[i] = cb[cb_i].first;
      cb[cb_i].second -= 1;
      if(cb[cb_i].second == 0) {
        cb_i += 1;
      }
      i++;
    } else {
      // もうCよりも大きな値しか持っていないので終了
      break;
    }
    if(cb_i == m) {
      break;
    }
  }

  ll sum = 0;
  for(auto v : a) sum += v;
  cout << sum << endl;
  return 0;
}
