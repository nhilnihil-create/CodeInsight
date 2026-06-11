#include<bits/stdc++.h>
#define fastio 	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;
typedef long long int ll;

double arr[3000];
double dp[3000][3000];
int n;
double find(int i, int h) {
	if (i >= n) {
		if (h >= (n + 1) / 2)
			return 1;
		return 0;
	}

	if (dp[i][h] > -1)
		return dp[i][h];

	return dp[i][h] = arr[i] * find(i + 1, h + 1) + (1 - arr[i]) * find(i + 1, h);
}


int main() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		// cout << arr[i] << endl;
	}

	memset(dp, -1, sizeof dp);
	cout << fixed << setprecision(10) << find(0, 0);
	return 0;
}


