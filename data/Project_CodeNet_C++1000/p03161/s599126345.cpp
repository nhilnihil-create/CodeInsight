#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define debug(x) cout << #x << " : " << x << '\n';


// code //
const int N = 100100;
int n, k;
int h[N], dp[N];

int main() {
	cin >> n >> k;
	for(int i = 0; i < n; ++i) 
		cin >> h[i];

	dp[0] = 0;
	for(int i = 1; i < n; ++i) {
		int j = i;
		dp[i] = INT_MAX;
		while(j >= 0 && j >= i - k)
			dp[i] = min(dp[i], dp[j] + abs(h[j--] - h[i]));
	}

	cout << dp[n-1];
}	
