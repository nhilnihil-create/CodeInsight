#include <bits/stdc++.h>
using namespace std;

const long long int mod = 1000000007;
const long long int big = 2999999999999999999;
const long long int small = -2999999999999999999;
#define ll long long int 
#define pb(a) push_back(a)
#define vll vector<long long int>
#define loop(i, n) for(long long int i=1;i<=n;i++)
#define loop0(i, n) for(long long int i=0;i<n;i++)
#define in(i) scanf("%lld", &i);
#define out(i) printf("%lld", i)

ll n;
vll adjacencyList[100001];
ll dp[100001][2];

void in2(ll& a, ll& b)
{
  in(a);
  in(b);
}
void in3(ll& a, ll& b, ll& c)
{
  in(a);
  in(b);
  in(c);
}

ll solve(ll p, ll node, int color)
{
  if(node>n)
    return 0;
  if(dp[node][color]!=-1)
    return dp[node][color];
  ll ans=1;
  if(color)
  {
    for(ll elem:adjacencyList[node])
    {
      if(elem!=p)
        ans=(ans%mod*(solve(node, elem, 1)+solve(node, elem, 0))%mod)%mod;
    }
  }
  else
  {
    for(ll elem: adjacencyList[node])
    {
      if(elem!=p)
        ans=(ans%mod*solve(node, elem, 1)%mod)%mod;
    }
  }
  return dp[node][color]=ans%mod;
}
int main()
{
  memset(dp, -1, sizeof(dp));
  in(n);
  ll u, v;
  loop(i, n-1)
  {
    in2(u, v);
    adjacencyList[u].pb(v);
    adjacencyList[v].pb(u);
  }
  ll ans = (solve(0, 1, 0)%mod + solve(0, 1, 1)%mod)%mod;
  cout<<ans<<"\n";
}