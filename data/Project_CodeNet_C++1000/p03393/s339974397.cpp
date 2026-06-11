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
  string s;
  cin >> s;
  if(s == "zyxwvutsrqponmlkjihgfedcba") {
    cout << -1 << endl;
  } else if(s.size() < 26) {
    vb b(26, false);
    rep(i, s.size()) b[s[i] - 'a'] = true;
    char c;
    rep(i, 26) {
      if(!b[i]) {
        c = i + 'a';
        break;
      }
    }
    cout << s + c << endl;
  } else {
    string t = s;
    ll i = 0;
    do {
      if(i == 1) {
        rep(i, s.size()) {
          cout << t[i];
          if(s[i] != t[i]) break;
        }
        cout << endl;
        return 0;
      }
      i++;
    } while(next_permutation(all(t)));
  }
}