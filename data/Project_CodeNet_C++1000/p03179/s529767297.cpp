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
ll m = (ll)(1e9+7);


 
int main()
{ 	
	FIN;
	#ifdef input
		freopen("T3.txt", "r", stdin);
	#endif
	
	int n;
	string pal;
	cin >> n >> pal;
	vector < vector <ll> > dp(3005,vector <ll>(3005,0));
	forr(i,1,n+1) dp[0][i]=1;
	
	int pos_min = 1, pos_max = n;
	
	forr(i,1,n)
	{
		if(pal[i-1]=='>')
		{
			ll acum = 0;
			for(int j=pos_max; j>=1; j--)
			{
				dp[i][j]=acum;
				acum+=dp[i-1][j];
				acum%=m;
				dp[i][j]%=m;
			}
			pos_max--;
		}
		else
		{
			ll acum = 0;
			for(int j=pos_min; j<=n; j++)
			{
				dp[i][j]=acum;
				acum+=dp[i-1][j];
				acum%=m;
				dp[i][j]%=m;
			}
			pos_min++;
		}
	}
	/*
	forn(i,n+1)
	{
		forn(j,n+1) cout << dp[i][j] << " ";
		cout << endl;
	}*/
	
	ll ans = 0;
	forr(i,pos_min,pos_max+1) ans+=dp[n-1][i], ans%=m;
	cout << ans << "\n";
	
    return 0;
}

