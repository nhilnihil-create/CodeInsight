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
int INF = (int)(1e9+7);
ll modu = (ll)(1e9+7);

vector <vector <int> > v(25,vector<int>(25));
vector < vector <ll> > dp(25,vector <ll>(2100000,-1));

ll funcion(int i, int n, int pos)
{
	//DBG(i); DBG(pos); RAYA;
	if(dp[i][pos]!=-1) return dp[i][pos];
	if(i==n) return 1LL;
	dp[i][pos]=0;
	forn(j,n)
	{
		if(v[i][j]==1 && ((1<<j)&pos)!=0)
		{
			dp[i][pos]+=funcion(i+1,n,((1<<j)^pos));
			dp[i][pos]%=modu;
		}
	}
	return dp[i][pos];
}


 
int main()
{ 	
	FIN;
	#ifdef input
		freopen("T3.txt", "r", stdin);
	#endif
	
	int n;
	cin >> n;
	forn(i,n)
	{
		forn(j,n) cin >> v[i][j];
	}
	int start = (1<<n)-1;
	cout << funcion(0,n,start) << "\n";
	
    return 0;
}
