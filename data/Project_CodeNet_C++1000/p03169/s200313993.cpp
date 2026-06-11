#include<bits/stdc++.h>
using namespace std;

#define ll long double
int N;
vector<vector<vector<ll>>> dp(310, vector<vector<ll>>(310, vector<ll>(310, -1)));

ll getTimes(ll a, ll b, ll c) {
	if (a + b + c == 0) {
		return 0.00;
	}
	if (dp[a][b][c] != -1) return dp[a][b][c];
	ll k = a + b + c;
	ll sum = N / k;
	if (a) {
		sum += (a / k) * getTimes(a - 1, b, c);
	}
	if (b) {
		sum += (b / k) * getTimes(a + 1, b - 1, c);
	}
	if (c) {
		sum += (c / k) * getTimes(a, b + 1, c - 1);
	}
	return dp[a][b][c] = sum;
}

int main() {
	cin >> N;
	int x;
	int a = 0, b = 0, c = 0;
	for (int i = 0; i < N; i++) {
		cin >> x;
		if (x == 1) a++;
		if (x == 2) b++;
		if (x == 3) c++;
	}
	ll res = getTimes(a, b, c);
	cout << fixed << setprecision(12) << res << endl;
	return 0;
}