//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define enl printf("\n")
#define case(t) printf("Case #%d: ", (t))
#define ni(n) scanf("%d", &(n))
#define nl(n) scanf("%lld", &(n))
#define nai(a, n) for (int i = 0; i < (n); i++) ni(a[i])
#define nal(a, n) for (int i = 0; i < (n); i++) nl(a[i])
#define pri(n) printf("%d\n", (n))
#define prl(n) printf("%lld\n", (n))
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vii vector<pii>
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
const double pi = acos(-1);
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
const int MAXN = 2e6 + 5;
const double eps = 1e-9;
using namespace std;

void solve()
{
  ll a, b, c, d;
  nl(a), nl(b), nl(c), nl(d);
  if (d < b || a < b)
  {
    printf("No\n");
    return;
  }
  if (d == b || b <= c+1) {
    if ((a % b) > c)
      printf("No\n");
    else
      printf("Yes\n");
    return;
  }
  ll g = __gcd(b, d);
  if (g <= b-1-c || a-((a-c-1)/b)*b < b) {
    printf("No\n");
    return;
  }
  printf("Yes\n");
  // ll delta = d - b;
  // if (c >= a && delta != 0)
  // {
  //   ll l = (c + 1 - a + delta - 1) / delta;
  //   a += l * delta;
  // }
  // if (b == d)
  // {
  //   if (c >= a)
  //   {
  //     printf("Yes\n");
  //     return;
  //   }
  //   ll nx = (a - c) % b + c;
  //   if ((a - c) % b == 0)
  //     nx += b;
  //   if (nx - b < 0)
  //     printf("No\n");
  //   else
  //     printf("Yes\n");
  //   return;
  // }
  // ll nx = (a - c) % b + c;
  // if ((a - c) % b == 0)
  //   nx += b;
  // if (nx - b < 0)
  // {
  //   printf("No\n");
  //   return;
  // }
  // if (b <= c + 1)
  // {
  //   printf("Yes\n");
  //   return;
  // }
  // if (b - 1 >= nx && nx >= c + 1)
  // {
  //   printf("No\n");
  //   return;
  // }
  // ll cur = a;
  // if (cur % b >= c + 1)
  // {
  //   printf("No\n");
  //   return;
  // }
  // a %= b, delta %= b;
  // if (__gcd(b, delta) == 1)
  // {
  //   printf("No\n");
  //   return;
  // }
  // //cur = 0;
  // //ll tmp = (c + 1 - a + b) % b;
  // unordered_set<ll> ax;
  // ll tmp = c + 1;
  // for (int i = 0; i <= tmp; i++)
  // {
  //   cur = (cur + delta) % b;
  //   if (ax.find(cur) != ax.end())
  //     break;
  //   ax.insert(cur);
  //   if (cur >= tmp)
  //   {
  //     printf("No\n");
  //     return;
  //   }
  // }
  // printf("Yes\n");
}

int main()
{
  int t;
  ni(t);
  while (t--)
    solve();
  return 0;
}
