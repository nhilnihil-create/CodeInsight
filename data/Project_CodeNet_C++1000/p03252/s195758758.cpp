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
  string s, t;
  cin >> s >> t;
  int n = s.size();
  vi a(26, -1), b(26, -1);
  vi x(n), y(n);
  int now = 0;
  rep(i, n) {
    int k = s[i] - 'a';
    if(a[k] == -1) {
      a[k] = now;
      now++;
    }
    x[i] = a[k];
  }
  now = 0;
  rep(i, n) {
    int k = t[i] - 'a';
    if(b[k] == -1) {
      b[k] = now;
      now++;
    }
    y[i] = b[k];
  }
  cout << (x == y ? "Yes" : "No") << endl;
}