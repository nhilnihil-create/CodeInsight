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
vector<vector<bool> > match(21, vector<bool>(21, false));
ll dp[21][1 << 21];

ll fun(int r , int mask) {
	if (r == n && mask == ((1 << n) - 1)) return 1;
	else if (r == n) return 0;
	ll &ans = dp[r][mask];
	if (ans != -1) return ans;
	ans = 0;
	for (int c = 0; c < n; ++c) {
		if (((1 << c)&mask) == 0) {
			if (match[r][c]) ans = (ans + fun(r + 1, mask | (1 << c))) % MOD;
		}
	}
	return ans;
}
int main() {



	cin >> n;
	int x;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> x;
			if (x == 1) match[i][j] = true;

		}
	}

	memset(dp, -1, sizeof(dp));
	cout << fun(0, 0);
}