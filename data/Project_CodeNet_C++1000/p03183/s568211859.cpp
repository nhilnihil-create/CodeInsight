#include <bits/stdc++.h>
using namespace std;
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);

typedef long long ll;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(int i = (a); i < (int) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(v,n) forn(i,n) cout << v[i] << " "; cout << endl
#define esta(x,c) ((c).find(x) != (c).end())
#define RAYA cerr << "===============================" << endl

struct block
{
	ll w, s, v;
};

bool compare(block &a, block &b)
{
	return a.w + a.s < b.w + b.s;
}

int main()
{
	FIN;
	
	int n;
	cin >> n;
	vector <block> v(n);
	forn(i,n) cin >> v[i].w >> v[i].s >> v[i].v;
	sort(all(v),compare); 
	
	//for(auto u : v) cout << u.w << " " << u.s << " " << u.v << "\n"; 
	
	int MAXS = 40000;
	
	vector <ll> dp(MAXS,0);
	
	for(auto u : v)
	{
		for(int i = min(u.s,MAXS-u.w); i>=0; i--)
		{
			dp[i+u.w] = max(dp[i+u.w],dp[i]+u.v);
		}
	}
	
	ll ans = 0;
	for(auto u : dp)
	{
		ans = max(ans,u);
	}
	
	cout << ans << "\n";
    return 0;
}
