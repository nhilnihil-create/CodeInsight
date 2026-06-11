#include "bits/stdc++.h"
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define mFOR(i, a, b) for (int i = a; i > b; i--)
#define MP make_pair
#define PB push_back
#define ALL(v) v.begin(), v.end()
#define N 100007
#define INF 1000000007
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll fceil(ll a, ll b) { return (a % b == 0 ? a / b : a / b + 1); }
int main()
{
   int n, ans = 0;
   cin >> n;
   vector<int> a(n, 0);
   for (int i = 0; i < n; i++)
   {
      cin >> a[i];
      int tmp = a[i];
      int l = 0, r = 32;
      while (l + 1 < r)
      {
         int mid = (l + r) / 2;
         if (tmp % (int)pow(2, mid) == 0)
            l = mid;
         else
            r = mid;
      }
      ans += l;
   }
   cout << ans << endl;
   return 0;
}
