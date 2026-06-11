#include <bits/stdc++.h>
using namespace std;
#define ll          long long
#define vl          vector<ll>
#define vi          vector<int>
#define pi          pair<int,int>
#define pl          pair<ll,ll>
#define all(a)      a.begin(),a.end()
#define mem(a,x)    memset(a,x,sizeof(a))
#define pb          push_back
#define mp          make_pair
#define F           first
#define S           second
#define endl 		"\n"
#define rep(i,a,b)  for(int i=a;i<b;i++)
#define fast_io     std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define trace(...) ZZ(#__VA_ARGS__, __VA_ARGS__);
template <typename Arg1> void ZZ(const char* name, Arg1&& arg1) {std::cerr << name << " = " << arg1 << endl;}
template <typename Arg1, typename... Args>void ZZ(const char* names, Arg1&& arg1, Args&&... args)
{
	const char* comma = strchr(names + 1, ',');
	std::cerr.write(names, comma - names) << " : " << arg1;
	ZZ(comma, args...);
}
const int maxn = 2e5 + 7;
ll BIT[maxn];
vi a(maxn), h(maxn);
ll query(int x, int n) {
	ll ret = 0;
	while (x > 0) {
		ret = max(BIT[x], ret);
		x -= (x & -x);
	}
	return ret;
}
void sum(int x, int n, ll k) {
	while (x <= n) {
		BIT[x] = max(k, BIT[x]);
		x += (x & -x);
	}
}
void solve() {
	int n;
	cin >> n;
	rep(i, 0, n)cin >> h[i];
	rep(i, 0, n)cin >> a[i];
	ll ans = 0, dp;
	rep(i, 0, n) {
		// trace(i, a[i], h[i], query(h[i], n))
		dp = query(h[i], n) + a[i];
		// trace(dp)
		ans = max(ans, dp);
		sum(h[i], n, dp);
	}
	cout << ans;
}
int main() {
	fast_io;
	int t = 1;
	// cin>>t;
	while (t--) {
		solve();
	}
	// cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	return 0;
}