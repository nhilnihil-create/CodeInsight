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
  map<string, int> mp;
  char last_word = '-';

  rep(i, 0, n) {
    string s;
    cin >> s;
    if (i) {
      if (s[0] != last_word) {
        cout << "No" << endl;
        return 0;
      }
    }
    last_word = s[((int)s.size()) - 1];
    mp[s]++;
    if (mp[s] > 1) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
}
