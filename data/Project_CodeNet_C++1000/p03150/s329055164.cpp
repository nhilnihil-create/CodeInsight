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
  ll n = s.size();
  string k = "keyence";
  bool ans = false;
  rep(i, 8) {
    string k1 = k.substr(0, i);
    string k2 = k.substr(i, 7 - i);
    string s1 = s.substr(0, i);
    string s2 = s.substr(n - 7 + i, 7 - i);
    if(s1 == k1 && s2 == k2) ans = true;
  }
  cout << (ans ? "YES" : "NO") << endl;
}