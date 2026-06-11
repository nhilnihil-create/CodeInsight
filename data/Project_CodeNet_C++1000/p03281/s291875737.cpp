#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
const ll mod = 1000000007;
const ll INF = 9223372036854775807;
#define Sort(a) sort(a.begin(), a.end())
#define Bsort(a) sort(a.begin(), a.end(), greater<ll>())
#define Pi acos(-1)

vector<long long> divisor(long long n) {
  vector<long long> ret;
  for (long long i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      ret.push_back(i);
    if (i * i != n) ret.push_back(n / i);
    }
  }
  sort(ret.begin(), ret.end());
  return ret;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << setprecision(15) << fixed;
  ll n;
  cin >> n;
  ll cnt = 0;
  rep(i,n) {
    if ((i+1)%2 == 1) {
      auto a = divisor(i+1);
      if (a.size() == 8) {
        cnt++;
      }
    }
  }
  cout << cnt << '\n';
}