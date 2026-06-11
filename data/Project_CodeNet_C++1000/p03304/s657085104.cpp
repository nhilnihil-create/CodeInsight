#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;

int main() {
  ll n,m,d;
  cin >> n >> m >> d;
  if (d == 0) {
    if (n == 1) {
      cout << m-1 << endl;
      return 0;
    }
    long double a = (long double)m / (long double)n;
    cout << setprecision(120) << a << endl;
    return 0;
   }
  ll suit = (max(n-(2LL*d),0LL) * 2LL) + (min(2LL*d,n) * 1LL);
  long double K = (((long double)suit / ((long double)n * (long double)n))) * (m-1);
  cout << setprecision(120) << K << endl;
  return 0;
}