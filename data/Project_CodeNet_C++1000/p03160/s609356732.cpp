/////////////////////////////////////////////DEFALT19/////////////////////////////////////////////////////////////

#include<bits/stdc++.h>
#define sp ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define vec vector<ll>
#define all(a) a.begin(),a.end()
#define endl "\n"
#define ll long long int
#define MP make_pair
#define f(i,a,n) for(ll i=a;i<n;i++)
#define rf(i,a) for(ll i=a-1;i>=0;i--)
#define in(a) for(auto& i:a)cin>>i
#define ol(a) for(auto i:a)cout<<i<<" ";cout<<endl;
#define ov(a) cout<<a<<endl
#define ov2(a,b) cout<<a<<" "<<b<<endl
#define ov3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define ov4(a,b,c,d) cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl
#define pb push_back
#define sv(a) sort(a.begin(),a.end());
#define pp pop_back
#define yes cout<<"Yes"<<endl;
#define no cout<<"No"<<endl;
using namespace std;

#define mod 100000007
#define MAX 300005

/*vector<vec> v(MAX), v2(MAX);
vector<bool> vis(MAX);

void dfs(ll root)
{
  vis[root] = true;
  for (auto i : v[root])
  {
    if (!vis[i])
    {
      dfs(i);
    }
  }
}

void bfs(ll u)
{
  queue<ll> q;

  q.push(u);
  vis[u] = true;

  while (!q.empty()) {

    ll f = q.front();
    q.pop();

    cout << f << " ";

    for (auto i : v[f])
    {
      if (!vis[i]) {
        q.push(i);
        vis[i] = true;
      }
    }
  }
}

pair<ll, ll> psum(vec a, ll s)
{
  ll i = 0, j = a.size() - 1;

  while (i < j)
  {
    if (a[i] + a[j] == s) return make_pair(i, j);
    if (a[i] + a[j] > s) j--;
    if (a[i] + a[j] < s) i++;
  }
  return make_pair(-1, -1);
}

int bin(vec a, ll l, ll r, ll x)
{
  if (r >= l)
  {
    ll mid  = l + (r - l) / 2;

    if (a[mid] == x) return mid;
    if (a[l] == x) return l;
    if (a[r] == x) return r;

    if (a[mid] > x)
      return bin(a, l, mid - 1, x);

    return bin(a, mid + 1, r, x);
  }
  return -1;
}*/

void solve()
{
  ll n; cin >> n;
  vec a(n); in(a);
  vec dp(n + 1, 0);
  dp[0] = 0;
  dp[1] = abs(a[1] - a[0]);
  f(i, 2, n + 1)
  {
    dp[i] = min(dp[i - 1] + abs(a[i - 1] - a[i]), dp[i - 2] + abs(a[i - 2] - a[i]));
  }
  // ol(dp);
  ov(dp[n - 1]);
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  sp
  ll t = 1;
  //cin >> t;
  while (t--) solve();
}