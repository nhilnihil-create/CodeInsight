#include<bits/stdc++.h>
using namespace std;

#define double long double
#define int long long
#define ALL(x) x.begin(),x.end()
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define pb(x) push_back(x)
#define eb emplace_back
#define SORT(ls) sort(ls.begin(), ls.end())
#define DESC(ls) sort(ls.rbegin(), ls.rend()) 
#define mp(x, y) make_pair(x, y)
#define INF 1000000000
#define F(i, a, n) for(i=a;i<n;i++)
#define SI(x) cin>>x
#define DI(x, y) cin>>x>>y
#define TI(x, y, z) cin>>x>>y>>z
#define FI(w, x, y, z) cin>>w>>x>>y>>z
#define SO(x) cout<<x<<"\n"
#define DO(x, y) cout<<x<<" "<<y<<"\n"
#define TO(x, y, z) cout<<x<<" "<<y<<" "<<z<< "\n"
#define FO(w, x, y, z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<"\n"
#define FASTER ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const int MOD = 1e9 + 7;
const int N = 1e5 + 5;
int dp[N][2];

inline int add(int x, int y)
{
	return ((x%MOD) + (y%MOD))%MOD;
}

inline int mul(int x, int y)
{
	return ((x%MOD)*(y%MOD))%MOD;
}



void dfs(int x, vi adj[], int p = - 1)
{
	dp[x][0] = dp[x][1] = 1;
	for(auto v: adj[x])
	{
		if(v == p)
			continue;
		dfs(v, adj, x);
		dp[x][0] = mul(dp[x][0], add(dp[v][0], dp[v][1]));
		dp[x][1] = mul(dp[x][1], dp[v][0]);
	}
}


int32_t main(void)
{
    FASTER;
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int i, j;
    int n;
    SI(n);
    vi adj[n];
    F(i, 0, n - 1)
    {
    	int u, v;
    	DI(u, v);
    	--u; --v;
    	adj[u].pb(v);
    	adj[v].pb(u);
    }
    dfs(0, adj);
    SO(add(dp[0][0], dp[0][1]));
    
    
    #ifdef LOCAL
    	cout<<endl<<endl<<"Time: "<<(float)clock()/CLOCKS_PER_SEC<<" seconds"<<endl;
    #endif
    return 0;
}