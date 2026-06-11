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
div_t div_mtwo(int a)
{
   div_t ret;
   ret.quot = a / -2;
   ret.rem = a % -2;
   if (ret.rem < 0)
   {
      ret.quot++;
      ret.rem += 2;
   }
   return ret;
}
int main()
{
   int n;
   div_t tmp;
   string ans = "";
   cin >> n;
   tmp.quot = n;
   tmp.rem = 0;
   while (tmp.quot != 0)
   {
      tmp = div_mtwo(tmp.quot);
      ans += '0' + tmp.rem;
   }
   reverse(ans.begin(), ans.end());
   ans = ans.empty() ? "0" : ans;
   cout << ans << endl;
   return 0;
}
