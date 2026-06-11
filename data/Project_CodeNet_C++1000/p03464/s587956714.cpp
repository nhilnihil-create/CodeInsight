#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
#define rep(i, n) for(ll i = 0;i < n;i++)
#define all(i) i.begin(), i.end()
template<class T, class U> bool cmax(T& a, U b) { if (a<b) {a = b; return true;} else return false; }
template<class T, class U> bool cmin(T& a, U b) { if (a>b) {a = b; return true;} else return false; }

int main() {
  cin.tie(0); ios::sync_with_stdio(false);

  ll n;
  cin >> n;
  vl a(n);
  rep(i, n) {
    cin >> a[n-1-i];
  }

  ll maxi = 2;
  ll mini = 2;
  auto f = [](ll n, ll m) {
    return (n+m-1)/m*m;
  };
  auto g = [](ll n, ll m) {
    ll t = n/m*m;
    if (t == n) return n+m-1;
    else return (n/m+1)*m-1;
  };
  rep(i, n) {
    ll tmp_maxi = g(maxi, a[i]);
    ll tmp_mini = f(mini, a[i]);
    //cerr << tmp_mini << " " << tmp_maxi << "\n" << endl;
    if (tmp_mini > tmp_maxi) {
      cout << -1 << endl;
      return 0;
    }
    maxi = tmp_maxi;
    mini = tmp_mini;
  }
  cout << mini << " " << maxi << endl;
}
