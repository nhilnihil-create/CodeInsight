#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; ++i)
#define rep2(i, x, n) for(int i = x, i##_len = (n); i < i##_len; ++i)
#define all(n) begin(n), end(n)
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
vi dir = {-1, 0, 1, 0, -1, -1, 1, 1, -1};

int main() {
  int n;
  cin >> n;
  vector<P> red(n), blue(n);
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    red[i] = P(a, b);
  }
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    blue[i] = P(b, a);
  }
  sort(all(red));
  reverse(all(red));
  sort(all(blue));
  rep(i, n) blue[i] = P(blue[i].second, blue[i].first);
  int ans = 0;
  for(auto rp : red) {
    int rx = rp.first;
    int ry = rp.second;
    rep(i, blue.size()) {
      int bx = blue[i].first;
      int by = blue[i].second;
      if(rx < bx && ry < by) {
        ans++;
        blue.erase(blue.begin() + i);
        break;
      }
    }
  }
  cout << ans << endl;
}