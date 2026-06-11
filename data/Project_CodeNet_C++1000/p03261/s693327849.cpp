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

  int n;
  cin >> n;
  map<string, bool> mp;
  string bef = "$";
  rep(i, 0, n) {
    string w;
    cin >> w;
    if (mp.count(w) || (i != 0 && bef[bef.size() - 1] != w[0])) {
      cout << "No" << endl;
      return 0;
    }
    mp[w] = true;
    bef = w;
  }

  cout << "Yes" << endl;
}
