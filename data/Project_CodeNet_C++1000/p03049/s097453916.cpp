#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; ++i)
#define rep2(i, x, n) for(ll i = x, i##_len = (n); i < i##_len; ++i)
#define all(n) begin(n), end(n)
using ll = long long;
using P = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
using vd = vector<double>;
vi dir = {-1, 0, 1, 0, -1, -1, 1, 1, -1};

int main() {
  ll n, ans = 0, ba = 0, a = 0, b = 0;
  cin >> n;
  rep(i, n) {
    string s;
    cin >> s;
    rep(i, s.size() - 1) if(s[i] == 'A' && s[i + 1] == 'B') ans++;
    if(s[0] == 'B' && s.back() == 'A')
      ba++;
    else if(s[0] == 'B')
      b++;
    else if(s.back() == 'A')
      a++;
  }
  if(ba > 0) {
    ans += ba - 1;
    if(a > 0) {
      a--;
      ans++;
    }
    if(b > 0) {
      b--;
      ans++;
    }
  }
  ans += min(a, b);
  cout << ans << endl;
}