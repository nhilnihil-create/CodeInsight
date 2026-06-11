// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

#define ll long long
#define ull unsigned long long
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ff first
#define ss second
#define vt vector
#define vll vt<ll>
#define pll pair<ll,ll>
#define vpll vt<pll>
#define vvll vt<vll>
#define all(v) v.begin(),v.end()
#define FOR(i,n) for(ll i=0;i<n;i++)
#define ffo(i,a,b) for(ll i=a;i<=b;i++)
#define rfo(i,a,b) for(ll i=a;i>=b;i--)
#define space cout<<"\n\n";
#define endl "\n"
#define pqmx priority_queue<ll>
#define pqmn priority_queue<ll,vll,greater<ll>>
#define fps(x,y) fixed<<setprecision(y)<<x
#define merg(a,b,c) set_union(a.begin(),a.end(),b.begin(),b.end(),inserter(c,c.begin()))
#define set_ar(arr,v) memset(arr,v,sizeof(arr))
#define go_t int testcases; cin>>testcases; ffo(caseno,1,testcases)

#define ctime auto start = high_resolution_clock::now()
#define etime auto stop = high_resolution_clock::now()
#define ptime auto z1z = duration_cast<microseconds>(stop-start); cout<<"Time elapsed : "<<z1z.count()<<" microseconds\n"

#define dbg1(x)             cout <<#x<<": "<<x<<'\n';
#define dbg2(x, y)          cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<<'\n';
#define dbg3(x, y, z)       cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<'\n';
#define dbg4(a, b, c, d)    cout <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<'\n';
#define dbg5(a, b, c, d, e) cout <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<<": "<<e<<'\n';

const ll mod = 1e9 + 7;
const ll N = 1e6 + 6;
const ll maxN = 1e5 + 5;
const ll MAX_SIZE = 2e6 + 6;
const ll INF = 0x3f3f3f3f3f3f3f3fll;
const double PI = 3.14159265359;

ll powerM(ll x, ll y, ll M = mod) { // default argument
	ll v = 1; x = x % M; while (y > 0) {if (y & 1)v = (v * x) % M; y = y >> 1; x = (x * x) % M;} return v;
}

ll power(ll x, ll y) {
	ll v = 1; while (y > 0) {if (y & 1)v = v * x; y = y >> 1; x = x * x;} return v;
}


ll n;
ll cache[maxN][2];
vector<ll> g[maxN];

ll dfs(ll k, ll par, ll col) // col is 1 => black // col is 0 => white
{
	ll &ans = cache[k][col];
	if (ans != -1)
		return ans;
	ans = 1;
	for (auto &it : g[k])
	{
		if (it == par)
			continue;
		if (!col)
			ans *= (dfs(it, k, 0) + dfs(it, k, 1));
		else
			ans *= dfs(it, k, 0);
		ans %= mod;
	}
	return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in1.txt", "r", stdin);
	freopen("out1.txt", "w", stdout);
#endif
	FIO
	memset(cache, -1, sizeof(cache));
	cin >> n;
	for (ll i = 1; i <= n - 1; i++)
	{
		ll u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	// 1 means black, 0 means white
	ll ans = dfs(1, 1, 0) + dfs(1, 1, 1);
	ans %= mod;
	cout << ans;
	return 0;
}
