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
   int n;
   string ans = "";
   cin >> n;
   while (n != 0)
   {
      if (n % 2 == 0)
      {
         ans += '0';
         n = -(n / 2);
      }
      else
      {
         ans += '1';
         n = -((n - 1) / 2);
      }
   }
   if (ans.empty())
      ans = "0";
   reverse(ans.begin(), ans.end());
   cout << ans << endl;
   return 0;
}
