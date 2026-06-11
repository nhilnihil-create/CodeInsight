#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 5e3 + 10, INF = 1e15 + 10;
int n, A, B, ans = INF, ar[N], dp[N];

int32_t main() {
	cin >> n >> A >> B;
	for (int i = 0; i < n; i++)
		cin >> ar[i];
	
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < i; j++)
			if (ar[j] > ar[i])
				dp[i] += A;
			else
				dp[i] += B;
	
	for (int i = 1; i < n; i++) {
		int sum = 0;
		for (int j = i - 1; j >= 0; j--) {
			if (ar[j] < ar[i])
				dp[i] = min(dp[i], dp[j] + sum);
			
			if (ar[j] > ar[i])
				sum += A;
			else
				sum += B;
		}
	}
	
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = i + 1; j < n; j++)
			if (ar[j] < ar[i])
				sum += B;
			else
				sum += A;
		ans = min(ans, sum + dp[i]);
	}
	cout << ans;
}