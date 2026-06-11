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
   ll n, ans = 0;
   cin >> n;
   vector<ll> a(n, 0LL), c(n, 0LL);
   for (ll i = 0LL; i < n; i++)
   {
      cin >> a[i];
      c[i] = a[i] - i - 1LL;
   }
   sort(c.begin(), c.end());
   for(ll i = 0; i < n; i++)
      ans += abs(c[i]-c[n/2LL]);
   cout << ans << endl;
   return 0;
}
