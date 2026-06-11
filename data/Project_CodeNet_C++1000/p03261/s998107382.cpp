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
  ll n;
  cin >> n;
  set<string> s;
  string last;
  bool ok = true;
  rep(i, n) {
    string w;
    cin >> w;
    if(i == 0) {
      last = w;
      s.insert(w);
      continue;
    }
    if(last.back() != w[0]) ok = false;
    if(s.count(w)) ok = false;
    last = w;
    s.insert(w);
  }
  cout << (ok ? "Yes" : "No") << endl;
}