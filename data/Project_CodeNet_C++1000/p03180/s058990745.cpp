#include <bits/stdc++.h>
using namespace std;
#define pii pair<ll,ll>
#define pll pair<long long, long long >
#define ll long long
#define lcm(a,b) (a)/__gcd((a),(b))*(b)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define maxn 100000
#define mod 1000000007
#define endl '\n'
#define trace(x) cerr << #x << ": " << x << endl;
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;

ll dir8[2][8] = {{1,-1,0,0,1,-1,1,-1},{0,0,1,-1,1,-1,-1,1}};
ll dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
ll m,n,row,col;
ll g[17][17];
ll cost[(1<<17)];
ll dp[(1<<17)];
vector <ll> v;
void solve()
{
  cin >> n;
  for(ll w=0;w<n;w++)
  {
    for(ll q=0;q<n;q++)cin >> g[w][q];
  }
  for(ll i=0;i<(1<<n);i++)
  {
    v.clear();
    for(ll w=0;w<n;w++)
    {
      if(i & (1<<w))v.pb(w);
    }
    for(ll w=0;w<(ll)v.size()-1;w++)
    {
      for(ll q=w+1;q<(ll)v.size();q++)
      {
        cost[i] += g[v[w]][v[q]];
      }
    }
  }
  ll finCost= 0;
  ll cs = 0;
  for(ll i=0;i<(1<<n);i++)
  {
    for(ll q=i;q>0;q = (q-1)&i)
    {
      dp[i] = max(dp[i], dp[i^q] + cost[q]);
    }
  }
  cout << dp[(1<<n)-1] << endl;

}
void test()
{
  ll t;
  //scanf("%d",&t);
  t= 1;
  for(ll test=1;test<=t;test++)
  {
    solve();
  }
}
int main()
{
  test();
  return 0;
}
