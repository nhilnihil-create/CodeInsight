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
using vd = vector<double>;
vi dir = {-1, 0, 1, 0, -1, -1, 1, 1, -1};

int main() {
  string s;
  cin >> s;
  int n = s.size();
  if(n < 26) {
    vb k(26, false);
    rep(i, n) k[s[i] - 'a'] = true;
    cout << s;
    rep(i, n + 1) {
      if(!k[i]) {
        cout << char('a' + i) << endl;
        return 0;
      }
    }
  }
  string os = s;
  do {
    if(os == s) continue;
    rep(i, n) {
      cout << s[i];
      if(os[i] != s[i]) return 0;
    }
  } while(next_permutation(all(s)));
  cout << -1 << endl;
}