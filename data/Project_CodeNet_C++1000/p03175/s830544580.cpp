//R<3S
#include <bits/stdc++.h>
#define hell 1000000007
#define PI 3.14159265358979323844
#define mp make_pair
#define pb push_back
#define fi first 
#define se second
#define ALL(v) v.begin(), v.end()
#define SORT(v) sort(ALL(v))  
#define REVERSE(v) reverse(ALL(v))
#define endl "\n"
#define vecmax(v) max_element(all(v))
#define vecmin(v) min_element(all(v))
#define GCD(m,n) __gcd(m,n)
#define LCM(m,n) m*(n/GCD(m,n))
#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define trav(x) for(auto i : x)
#define sz(a) (int)a.size()
#define sl(a) (int)a.length()
#define int long long
#define ld long double 
#define pii std::pair<int, int> 
#define pll std::pair<ll, ll>  
#define vi vector<int>  
#define vl vector<ll>
#define vvi vector<vi > 
#define vii vector<pii >
#define mii map<int,int>
#define mll map<ll,ll>


using namespace std;

int n;
vector <int> adj[100005];
int dp[100005][2];

int dfs(int node,int color,int parent) 
{
	if(dp[node][color]!=-1)return dp[node][color];
    int sum=1;
    for(int i = 0;i < adj[node].size();++i)    
    {
         if(adj[node][i]!=parent)
        	{
        		if(color==0)sum*=(dfs(adj[node][i],1-color,node)+dfs(adj[node][i],color,node));
        		else sum*=dfs(adj[node][i],1-color,node);
        		sum%=hell;
        	}
        	
    }
    return dp[node][color]=sum%hell;
}


void solve()
  {
	cin>>n;
	int x,y;
	rep(i,n-1)
	{
		cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	rep(i,100005)dp[i][0]=-1,dp[i][1]=-1;
	cout<<(dfs(1,1,-1)+dfs(1,0,-1))%hell;


  }



signed main()
{
   std::ios_base::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   int t;
   t=1;
   //cin>>t;
   while(t--)
    {
        solve();
    }


   return 0;
}
	