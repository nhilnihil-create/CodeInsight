#include "bits/stdc++.h"
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define mFOR(i, a, b) for (int i = a; i > b; i--)
#define MP make_pair
#define PB push_back
#define ALL(v) v.begin(), v.end()
#define N 100007
#define INF 10000007
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll fceil(ll a, ll b) { return (a % b == 0 ? a / b : a / b + 1); }
int main()
{
   ll n, ans = INF, sum_less_b = 0, sum_c = 0;
   cin >> n;
   vector<ll> a(n, 0LL), c(n, 0LL);
   for (ll i = 0LL; i < n; i++)
   {
      cin >> a[i];
      c[i] = a[i] - i - 1LL;
   }
   sort(c.begin(), c.end());
   for (ll i = 0LL; i < n; i++)
      sum_c += c[i];
   ans = sum_c - n * c[0];
   for (ll i = 0LL; i < n - 1LL; i++)
   {
      sum_less_b += c[i];
      ll tmp = sum_c - 2LL * sum_less_b;
      if (2LL * (i + 1LL) >= n)
         tmp += (2LL * (i + 1LL) - n) * c[i];
      else
         tmp += (2LL * (i + 1LL) - n) * c[i + 1LL];
      ans = min(ans, tmp);
   }
   cout << ans << endl;
   return 0;
}
