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
  ll a;
  cin >> a;
  set<ll> st;
  rep2(i, 2, 1e6 + 1) {
    st.insert(a);
    if(a % 2 == 0)
      a = a / 2;
    else
      a = 3 * a + 1;
    if(st.count(a)) {
      cout << i << endl;
      return 0;
    }
  }
}