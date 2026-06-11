#include <bits/stdc++.h>

/*............................*/

#define uint uint64_t
#define mx 100001
#define ll long long int
#define ull unsigned long long int
#define pii pair<int, int>
#define pll pair<long long int, long long int>
#define mp make_pair
#define pb push_back
#define inf INT_MAX
#define pi acos(-1)
#define eps 1e-8
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / __gcd(a, b)
#define input(ara, n)          \
   for (int i = 0; i < n; i++) \
   scanf("%d", &ara[i])
#define inputl(ara, n)                   \
   for (long long int i = 0; i < n; i++) \
   scanf("%lld", &ara[i])
#define pf(a) printf("%d\n", a);
#define pfl(a) printf("%lld\n", a);
#define pfi(a) printf("%d ", a);
#define pfll(a) printf("%lld ", a);
#define sc(a) scanf("%d", &a)
#define scc(a, b) scanf("%d %d", &a, &b)
#define sccdbl(a, b) scanf("%lf %lf", &a, &b)
#define sccc(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define scccdbl(a, b, c) scanf("%lf %lf %lf", &a, &b, &c)
#define scl(a) scanf("%lld", &a)
#define sccl(a, b) scanf("%lld %lld", &a, &b)
#define scccl(a, b, c) scanf("%lld %lld %lld", &a, &b, &c)
using namespace std;
vector<pii> node[100001];
bool visited[100001];
ll color[100001];
void dfs(ll u)
{
   visited[u] = true;
   for (ll i = 0; i < node[u].size(); i++)
   {
      ll v = node[u][i].first;
      ll w = node[u][i].second;
      if (!visited[v])
      {
         if (w % 2 == 0)
         {
            color[v] = color[u];
         }
         else
         {
            color[v] = 1 - color[u];
         }
         dfs(v);
      }
   }
}
int main()
{
   // int t;
   // sc(t);
   // while (t--)
   // {

   // }
   ll n, u, v, w;
   scl(n);
   for (ll i = 0; i < n - 1; i++)
   {
      scccl(u, v, w);
      node[u].pb(mp(v, w));
      node[v].pb(mp(u, w));
   }
   color[1] = 1;
   dfs(1);
   for (ll i = 1; i <= n; i++)
   {
      pfl(color[i]);
   }
   return 0;
}
