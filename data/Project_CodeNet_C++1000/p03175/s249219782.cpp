#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector<ll> vi;
typedef long double td;
typedef vector<td> vd;
typedef pair<ll,ll> ii;
typedef vector<ii> vii; typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = ll(a); i < (ll)(b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define show(v,n) cerr << #v << " = "; forn(i,n) cerr << v[i] << " "; cerr << endl;
#define esta(x,c) ((c).find(x) != (c).end())
#define RAYA cerr << "===============================" << endl
int MAXN = 500005;
ll INF = (ll)(1e18+7);
ll modu = (ll)(1e9+7);

vector < vector <int> > v(100005);
vector <bool> visto(100005,false);
vector < vector <ll> > dp(100005,vector <ll>(4,1));

void DFS(int n)
{
	visto[n]=true;
	//DBG(n);
	bool d = false;
	vector < vector <ll> > ans(3);
	for(auto u : v[n])
	{
		if(!visto[u])
		{
			DFS(u);
			d=true;
			ans[0].pb(dp[u][0]+dp[u][1]);
			ans[1].pb(dp[u][0]);
		}
	}
	for(auto u : ans[0])
	{
		dp[n][0]*=u;
		dp[n][0]%=modu;
	}
	for(auto u : ans[1])
	{
		dp[n][1]*=u;
		dp[n][1]%=modu;
	}
}
 
int main()
{ 	
	FIN;
	#ifdef input
		//("T1.txt", "r", stdin);
	#endif
	
	int n;
	cin >> n;
	forn(i,n-1)
	{
		int x, y;
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}
	
	DFS(1);
	
	//forr(i,1,n+1) cout << dp[i][0] << " " << dp[i][1] << "\n";
	cout << (dp[1][0]+dp[1][1])%modu << "\n";
	
	
    return 0;
}
