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
const ll maxN = 1e5 + 5;
const ll MAX_SIZE = 2e6 + 6;
const ll INF = 0x3f3f3f3f3f3f3f3fll;
const double PI = 3.14159265359;

ll powerM(ll x, ll y, ll M = MOD) { // default argument
	ll v = 1; x = x % M; while (y > 0) {if (y & 1)v = (v * x) % M; y = y >> 1; x = (x * x) % M;} return v;
}

ll power(ll x, ll y) {
	ll v = 1; while (y > 0) {if (y & 1)v = v * x; y = y >> 1; x = x * x;} return v;
}

int n, k;
int a[105];
int dp[105][maxN];

// here dp[i][j] will store the prefix sum of the diff no. of ways to distribute
// j candies among i children with the given upper bound constraints

int solve(int child, int candy) {
	if (candy < 0) return 0;
	if (candy == 0) return 1;
	if (child == n + 1) return 1;
	//
	int& dd = dp[child][candy];
	if (dd != -1) return dd;
	// max amt of candies that can be given to the child
	int mini = min(candy, a[child]);
	dd = solve(child + 1, candy) - solve(child + 1, candy - mini - 1) + MOD;
	dd %= MOD;
	dd += solve(child, candy - 1);
	dd %= MOD;
	return dd;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif
	FIO
	// Ashishgup you're great bro
	cin >> n >> k;
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= n; i++) cin >> a[i];
	int ans = solve(1, k) - solve(1, k - 1) + MOD;
	ans %= MOD;
	cout << ans;
	return 0;
}
