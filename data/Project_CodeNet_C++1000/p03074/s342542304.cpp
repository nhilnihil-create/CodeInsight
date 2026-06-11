#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, k;
  string s;
  cin >> n >> k >> s;
  vector<int> one, zero;
  if (s[0] == '0')
    one.push_back(0);
  char bef = s[0];
  int c = 1;
  rep(i, 1, n) {
    if (bef == s[i]) {
      c++;
    } else {
      if (bef == '0')
        zero.push_back(c);
      else
        one.push_back(c);
      c = 1;
    }
    bef = s[i];
  }
  if (bef == s[n - 1]) {
    if (bef == '0')
      zero.push_back(c);
    else
      one.push_back(c);
  }

  ll ans = 0;
  rep(i, 0, n) {
    ll sumone = 0, sumzero = 0;
    rep(j, i, min((int)one.size(), i + k + 1)) {
      sumone += one[j];
      if (j < min((int)zero.size(), i + k))
        sumzero += zero[j];
    }
    chmax(ans, sumone + sumzero);
  }
  cout << ans << endl;
}