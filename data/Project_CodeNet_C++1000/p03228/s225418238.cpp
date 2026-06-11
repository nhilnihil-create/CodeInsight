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

  ll a, b, k;
  cin >> a >> b >> k;

  rep(i, k) {
    if (i%2) {
      if (b%2) {
        b--;
      }
      a += b/2;
      b -= b/2;
    } else {
      if (a%2) {
        a--;
      }
      b += a/2;
      a -= a/2;
    }
  }
  cout << a << " " << b << endl;
}
