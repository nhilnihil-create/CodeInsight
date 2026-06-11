#include <bits/stdc++.h>
using namespace std;
#define PI 3.14159265358979323
#define ll long long int
#define vi vector <int>
#define vl vector <ll>
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define MOD 1000000007
ll power(ll a, ll b) { //a^b
	ll res = 1;
	a = a % MOD;
	while (b > 0) {
		if (b & 1) {res = (res * a) % MOD; b--;}
		a = (a * a) % MOD;
		b >>= 1;
	}
	return res;
}

ll gcd(ll a, ll b) {return (b == 0) ? a : gcd(b, a % b);}

int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin >> n;
	vl v(n);
	for (ll i = 0; i < n; i++)
		cin >> v[i];
	vl pre(n);
	pre[0] = v[0];
	for (ll i = 1; i < n; i++)
		pre[i] = pre[i - 1] + v[i];
	vector <vl> dp(n, vl (n, 1e15));
	for (ll l = n - 1; l >= 0; l--) {
		for (ll r = l; r < n; r++) {
			if (r == l) {
				dp[l][r] = 0;
				continue;
			}
			for (ll k = l; k < r; k++)
				dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] + pre[r] - (l > 0 ? pre[l - 1] : 0));
		}
	}
	cout << dp[0][n - 1];
}
