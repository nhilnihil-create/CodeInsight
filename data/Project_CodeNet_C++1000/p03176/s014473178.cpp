#define _GLIBCXX_DEBUG
#pragma GCC optimize ("trapv") // kills the program on integer overﬂows (but is really slow). 
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
const ll maxN = 2e5 + 5;
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
vll a(maxN, 0);
vll h(maxN, 0);
vll seg(4 * maxN, 0);
vll dp(maxN, 0);

ll query(ll l, ll r, ll pos, ll ql, ll qr) {
	if (ql <= l && qr >= r)
		return seg[pos];
	if (ql > r || qr < l)
		return -1;
	ll mid = (l + r) / 2;
	return max(query(l, mid, 2 * pos + 1, ql, qr), query(mid + 1, r, 2 * pos + 2, ql, qr));
}

void update(ll l, ll r, ll pos, ll val, ll u_pos) {
	if (l == r) {
		seg[pos] = max(val, seg[pos]);
		return;
	}
	if (u_pos > r || u_pos < l)
		return;
	ll mid = (l + r) / 2;
	if (u_pos <= mid)
		update(l, mid, 2 * pos + 1, val, u_pos);
	else
		update(1 + mid, r, 2 * pos + 2, val, u_pos);
	seg[pos] = max(seg[2 * pos + 1]	, seg[2 * pos + 2]);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in1.txt", "r", stdin);
	freopen("out2.txt", "w", stdout);
#endif
	FIO
	cin >> n;
	FOR(i, n) {
		cin >> h[i + 1];
	}
	FOR(i, n) {
		cin >> a[i + 1];
	}
	// update(0, n - 1, 1, a[1], h[1] - 1);
	for (int flower = 1; flower <= n; ++flower) {
		ll v = 0;
		if (h[flower] != 1)
			v = query(1, n, 0, 1, h[flower] - 1);
		dp[h[flower]] = max(dp[h[flower]], v + a[flower]);
		update(1, n, 0, dp[h[flower]], h[flower]);
	}
	ll ans = 0;
	FOR(i, n) ans = max(ans, dp[i + 1]);
	cout << ans << endl;
	return 0;
}