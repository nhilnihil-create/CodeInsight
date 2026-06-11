#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define debug(x) cout << #x << " : " << x << '\n';


// code //
const int N = 100100;
int n;
int h[N], dp[N];

int main() {
	cin >> n;
	for(int i = 0; i < n; ++i) 
		cin >> h[i];

	dp[0] = 0;
	dp[1] = abs(h[1] - h[0]);
	for(int i = 2; i < n; ++i) 
		dp[i] = min(dp[i-1] + abs(h[i-1] - h[i]), dp[i-2] + abs(h[i-2] - h[i]));

	cout << dp[n-1];
}