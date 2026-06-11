
#include<bits/stdc++.h>

using namespace std;

/*helpfull*/
using vl  = vector<long long>;
using vpl = vector<pair<long long, long long>>;
using vs = vector<string>;
using pl  = pair<long long, long long>;
using ll  = long long int;
using vb  = vector<bool>;


struct hash_pair {
	template <class T1, class T2>
	size_t operator()(const pair<T1, T2>& p) const
	{
		auto hash1 = hash<T1> {}(p.first);
		auto hash2 = hash<T2> {}(p.second);
		return hash1 ^ hash2;
	}
};
// #ifndef ONLINE_JUDGE
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
// #endif

// shortcut macros
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mp              make_pair
#define fi              first
#define se              second
// #define mt              make_tuple
#define pb              push_back
#define all(x)          (x).begin(), (x).end()
#define ini(a, v)       memset(a, v, sizeof(a))
#define rep(i, a, n)    for(ll i=a ; i<n ; ++i)
#define For(i, n)       rep(i, 0, n)
#define sz(x)           (int((x).size()))
#define ump(x,y)        unordered_map<x,y>
#define umpr(x,y,z)     unordered_map<x,y,z>
void printcase(ll &x) {
	cout << "Case #" << x << ": ";
}
void read(vector<ll>&v, ll &n) {
	For(i, n)
	cin >> v[i];
}
void read(ll &x) {
	cin >> x;
}
void read(string &s) {
	cin >> s;
}
void read(int &x) {
	cin >> x;
}
void read(ll a[], ll &n) {
	For(i, n)
	cin >> a[i];
}
void print() {
	cout << endl;
}
void write(vector<ll>&v, ll &n) {
	For(i, n)
	cout << v[i] << " ";
	cout << endl;
}
void write(vector<ll>&v) {
	ll n = v.size();
	For(i, n)
	cout << v[i] << " ";
	cout << endl;
}
void write(ll x) {
	cout << x << endl;
}
void write(string &s) {
	cout << s << endl;
}
void write(int &x) {
	cout << x << endl;
}
void write(ll a[], ll &n) {
	For(i, n)
	cout << a[i] << " ";
	cout << endl;
}
const ll mod = 1e9 + 7;


// ll count_path(ll x, ll y, ll &n, ll &m, vector<string> &v, vector<vector<ll>> &memo) {
//     if (memo[x][y] != -1)
//         return memo[x][y] % mod;
//     if (x == n - 1 && y == m - 1)
//         memo[x][y] = 1;
//     else if (x >= n || y >= m)
//         memo[x][y] = 0;
//     else if (v[x][y] == '#')
//         memo[x][y] = 0;
//     else
//         memo[x][y] = (count_path(x + 1, y, n, m, v, memo) % mod + count_path(x, y + 1, n, m, v, memo) % mod) % mod;

//     return memo[x][y] % mod;
// }

// ll countways(ll &n, vector<ll> &a, vector<vector<ll>> &memo, ll ch, ll ca) {
// 	if (memo[ch][ca] != -1)
// 		return (memo[ch][ca] % mod);
// 	else if (ch == n && ca == 0)
// 		memo[ch][ca] = 1;
// 	else if ( ch == n )
// 		memo[ch][ca] = 0;
// 	else {

// 		memo[ch][ca] = 0;
// 		ll b = a[ch];
// 		for (ll i = 0; i <= min(b, ca); i++) {
// 			// a[ch] -= i;
// 			memo[ch][ca] += (countways(n, a, memo, ch + 1, ca - i) % mod);
// 			// a[ch] += i;
// 		}
// 	}

// 	return memo[ch][ca] % mod;
// }


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	IOS;
	ll n, k;
	cin >> n >> k;
	vl a(n + 1);
	For(i, n)
	cin >> a[i + 1];
	vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, 0));

	for (int i = 0; i <= n; i++)
		dp[i][0] = 1;
	for (int i = 1; i <= k; i++)
		dp[0][k] = 0;

	vector<ll> pre(k + 1, 1);
	ll a1, b, m;


	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= k; j++) {

			m = min(a[i], j);
			a1 = j - m; b = j;
			if (a1 == 0)
				dp[i][j] += (pre[b] % mod);
			else
				dp[i][j] += ((pre[b] - pre[a1 - 1] + mod) % mod);

			dp[i][j] = (dp[i][j] % mod);

			// for (ll k = 0; k <= min(a[i], j); k++) {
			// 	dp[i][j] += dp[i - 1][j - k];
			// }
		}
		pre[0] = dp[i][0];
		for (ll j = 1; j <= k; j++) {
			pre[j] = ( (    (pre[j - 1] % mod)  +   (dp[i][j] % mod)  ) % mod );
		}
	}

	cout << (dp[n][k] % mod) << endl;

	return 0;
}

