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
  vl a(n), b(n);
  ll asum = 0;
  ll bsum = 0;
  rep(i, n) {
    cin >> a[i];
    asum += a[i];
  }
  rep(i, n) {
    cin >> b[i];
    bsum += b[i];
  }

  ll t = bsum-asum;

  cerr << t << endl;
  rep(i, n) {
    t -= max(0LL, b[i]-a[i]+1)/2;
  }

  if (t < 0) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }
}
