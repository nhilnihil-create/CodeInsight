#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define ff first
#define ss second
#define vll vector<ll>
#define pll pair<ll,ll>
#define vpll vector<pll>
#define vvll vector<vll>
#define all(v) v.begin(),v.end()
#define itr(r,v) for(auto r=v.begin();r!=v.end();r++)
#define FOR(i,n) for(ll i=0;i<n;i++)
#define ffo(i,a,b) for(ll i=a;i<=b;i++)
#define rfr(i,a,b) for(ll i=a;i>=b;i--)
#define space cout<<"\n\n";
#define endl "\n"
#define pqmx priority_queue<ll>
#define pqmn priority_queue<ll,vll,greater<ll>>
#define fps(x,y) fixed<<setprecision(y)<<x
#define merg(a,b,c) set_union(a.begin(),a.end(),b.begin(),b.end(),inserter(c,c.begin()))
#define set_ar(arr,v) memset(arr,v,sizeof(arr))
#define ctime auto sttart = high_resolution_clock::now()
#define etime auto sttop = high_resolution_clock::now()
#define go_t ll testcases; cin>>testcases; for(ll caseno= 1 ;caseno <= testcases; caseno++)
#define ptime auto z1z = duration_cast<microseconds>(sttop-sttart); cout<<"\nTime taken : "<<z1z.count()<<" microseconds\n"
#define dbg1(x)             cout <<#x<<": "<<x<<'\n';
#define dbg2(x, y)          cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<<'\n';
#define dbg3(x, y, z)       cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<'\n';
#define dbg4(a, b, c, d)    cout <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<'\n';
#define dbg5(a, b, c, d, e) cout <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<<": "<<e<<'\n';

using namespace std;
using namespace std::chrono;

const ll MOD = 1e9 + 7;
const ll N = 1e5 + 5;
const ll maxN = 21 + 5;
const ll MAX_SIZE = 2e6 + 6;
const ll INF = 0x3f3f3f3f3f3f3f3fll;
const double PI = 3.14159265359;

ll powerM(ll x, ll y, ll M = MOD) { // default argument
	ll v = 1; x = x % M; while (y > 0) {if (y & 1)v = (v * x) % M; y = y >> 1; x = (x * x) % M;} return v;
}

ll power(ll x, ll y) {
	ll v = 1; while (y > 0) {if (y & 1)v = v * x; y = y >> 1; x = x * x;} return v;
}

int n;
int a[maxN][maxN];
int dp[23][1 << 21]; // we need only 1<<21 as in 1<<x we have x+1 digits

// in mask -> set bit will represent that the woman hasn't found any particular match

int solve(int idx, int mask) {
	if (idx == n) {
		if (mask == 0) //  means all the women have been paired up with different men
			return 1;
		else
			return 0;
	}
	if (dp[idx][mask] != -1)
		return dp[idx][mask];
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (a[idx][i] == 1 && (mask & (1 << i))) {
			ans += solve(idx + 1, mask ^ (1 << i));
			if (ans > MOD) ans -= MOD;
		}
	}
	return dp[idx][mask] = ans;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif
	FIO
	memset(dp, -1, sizeof(dp));
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			cin >> a[i][j];
	}
	cout << solve(0, (1 << n) - 1);
	return 0;
}
