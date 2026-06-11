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
  set<P> st;
  rep2(i, 1, n) {
    ll j = n - i + 1 - n % 2;
    ll ii = i;
    if(ii > j) swap(ii, j);
    st.insert({ii, j});
  }
  cout << n * (n - 1) / 2 - st.size() << '\n';
  rep2(i, 1, n) rep2(j, i + 1, n + 1) if(!st.count({i, j})) cout << i << ' '
                                                                 << j << '\n';
}