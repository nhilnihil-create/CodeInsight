   //____________________________________________________________________
  //________________________________NAMAN_______________________________
 //________________________________TALAYCHA______________________________
//_________________________________________________________________________

#include <bits/stdc++.h>
#define ll              long long
#define int             long long
#define pmin            priority_queue < ll, vector<ll>, greater<ll> >
#define pmax            priority_queue <ll>
#define endl            '\n'
#define mii             map<ll , ll >
#define pii             pair< ll, ll >
#define vi              vector<ll>
#define all(a)          (a).begin(), (a).end()
#define DEBUG           cerr<<"/n>>>I'm Here<<</n"<<endl;
#define rep(i, a, b )   for (ll i = a; i < b; i++)
#define rrep(i, a, b)   for (ll i = a; i >= b; i--)
#define bs              binary_search
#define present(c, x)   ((c).find(x) != (c).end())
#define cpresent(c, x)  (find(all(c), x) != (c).end())
#define p1(i)           cout<<i<<endl;
#define p2(i,j)         cout<<i<<" "<<j<<endl;
#define line            cout<<endl;
#define prt(s,b,n)      rep(i,(b),(n)) { cout<<(s)[i]<<" ";} line
#define lower(u)        transform(u.begin(), u.end(), u.begin(), ::tolower);  //convert string u to lowercase;
#define upper(u)        transform(u.begin(), u.end(), u.begin(), ::toupper);
#define tr(container, it) \
for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define hell 1e6+3
#define mod 998244353

using namespace std;

//_________________________________________________________________________________________________________
//__________________________________________START____________________________________________________________

//................EVERY COIN HAS TWO SIDES...............................................................................................................
ll N=100005;
vector<ll> g[100005];
ll vis[100005];
ll d[100005];
ll ans=0;
ll dfs(ll u, ll p)
{
    if(d[u]) return d[u];
   for(auto v : g[u])
   {  
      if(v==p) continue;
      d[u]=max(d[u],1+dfs(v,u));
   }
   ans=max(ans,d[u]);
   return d[u];
}

void solve()
{
  ll n,m,u,v; 
  cin>>n>>m;
  rep(i,0,m)
  {cin>>u>>v;
    g[u].push_back(v);
  } 
  rep(i,1,n+1) d[i]=0;

  rep(i,1,n+1)
  dfs(i,-1);
 p1(ans)

}

//__________________________________________________________________________________________________________
//__________________________________________END______________________________________________________________

signed main() 
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  #ifndef ONLINE_JUDGE 
  freopen("input.txt" , "r", stdin);
  freopen("out12.txt" , "w", stdout);
  #endif  

  ll TESTS = 1;
 //  cin>>TESTS;
  while (TESTS--) 
  {
    solve();
  }
  return 0;
}
