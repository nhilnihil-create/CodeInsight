#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <iomanip> 
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<bool> vb;
typedef vector<ull> vul;
typedef vector<pair<ll, ll>> vpl;
typedef pair<ll, ll> pl;
#define For(i, n) for(ll i = 0; i < n; i++)
#define len(n) (ll)(n).size()
#define Sort(a) sort(a.begin(), a.end())
#define Reverse(a) reverse(a.begin(), a.end())
ll dp[410][410];
ll sm[410][410];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin >> n;
	vl a(n);
	For(i, n) For(j, n) dp[i][j] = 1e15;
	For(i, n) {
		cin >> a[i];
		dp[i][i] = 0;
	}
	For(i, n) {
		For(j, i + 1) {
			sm[j][i] = sm[j][i - 1] + a[i];
			//cout << sm[j][i] << ' ' << j << ' ' << i << endl;
		}
	}
	For(i, n) {
		for (ll j = i; j >= 0; j--) {
			for (ll k = j; k < i; k++) {
				dp[j][i] = min(dp[j][i], dp[j][k] + dp[k + 1][i] + sm[j][i]);
			}
			//cout << dp[j][i] << ' ' << j << ' ' << i << endl;
		}
	}
	cout << dp[0][n - 1];
	return 0;
}