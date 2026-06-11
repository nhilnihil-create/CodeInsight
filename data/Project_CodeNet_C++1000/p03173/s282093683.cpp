#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> arr;
typedef vector<arr> matrix;
typedef vector<ll> longarr;
typedef vector<longarr> longmat;
typedef map<int, arr> graph;
typedef vector<char> chararr;
typedef vector<chararr> charmat;
typedef pair<int, int> fraction;
ll MOD = 1000000007;
int n;
ll slimes[400];
ll pref[400];
longmat dp(400, longarr(400, -1));
ll psum(int i, int j) {
	ll ans = 0;
	ans += pref[j];
	if (i != 0) ans -= pref[i - 1];
	return ans;
}
ll fun(int i, int j) {
	if (i == j) return 0;
	ll &ans = dp[i][j];
	if (ans != -1) return dp[i][j];
	ans = LLONG_MAX;
	for (int k = i; k < j; ++k) {
		ans = min(ans, fun(i, k) + fun(k + 1, j) + psum(i, k) + psum(k + 1, j) );
	}
	return ans;
}

int main() {

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> slimes[i];
	}
	partial_sum(slimes, slimes + n, pref);
	cout << fun(0, n - 1);

}