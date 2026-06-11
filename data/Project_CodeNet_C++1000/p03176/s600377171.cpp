#include<bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define fr(i,k) for(i=0;i<k;i++)
#define deb(x) cerr<<#x<<"  = "<<x<<endl;
#define deb2(x,y) cerr<<#x<<" ="<<x<<endl<<#y<<" ="<<y<<endl;
#define SZ(x) (x).size();
#define ll long long
#define mod 1000000007
#define ff first
#define ss second
#define pb push_back
#define em emplace_back
#define ulli unsigned long long int
#define inf 1e18
#define endl "\n"
typedef vector<vector<ll>> vvll;
typedef vector<ll> vll;
typedef vector<pair<ll, ll>> vpll;
typedef pair<ll, ll> pll;
typedef vector<bool> vb;
void solve();

int main() {
	fastio;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ll t;
	t = 1;

	//cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}


inline void solve()
{
	ll n, i, j, ans;
	cin >> n;

	ll h[n], a[n];
	map<ll, ll> m;

	for (i = 0; i < n; i++)
		cin >> h[i];

	for (i = 0; i < n; i++)
		cin >> a[i];

	vll dp(n);
	dp[0] = a[0];
	m[h[0]] = dp[0];
	ans = dp[0];

	for (i = 1; i < n; i++)
	{
		dp[i] = a[i];

		auto it = m.lower_bound(h[i] + 1);
		if (it != m.begin())
		{
			it--;
			dp[i] += it->second;
		}

		m[h[i]] = dp[i];

		it = m.upper_bound(h[i]);

		while (it != m.end() && it->second <= dp[i])
		{
			auto temp = it;
			temp++;
			m.erase(it);
			it = temp;
		}
		ans = max(ans, dp[i]);
	}

	cout << ans << endl;
}
