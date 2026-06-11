#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define EPS (1e-7)
#define INF (1e9)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const double PI = acos(-1);
const ll MOD = 1000000007;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
 
template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
  ll n, m, d; cin >> n >> m >> d;

  ll k;
  if (d == 0) k = n;
  else k = min (2 * d,n);
  double p = double(2*n - k) / double(n*n);
  double ans = (m-1) * p;

  cout << fixed << setprecision(10) << ans <<endl;
}