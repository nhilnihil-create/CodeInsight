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

ll f(ll n) {
  if(n % 2)
    return (n + 1) / 2 % 2;
  else
    return n / 2 % 2 ^ n;
}

int main() {
  ll a, b;
  cin >> a >> b;
  a--;
  cout << (f(a) ^ f(b)) << endl;
}
