#include<bits/stdc++.h>
using namespace std;
const int M = 2e5 + 5;
const int P = 1e9 + 7;
int a[M], w[M], dp[M];
inline int Mod(int x) {
	return x >= P ? x - P : x;
}
int main() {
	int n; cin >> n;
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
	dp[n] = w[a[n]] = 1;
	for (int i = n - 1; i > 0; --i) {
        if (a[i] == a[i + 1]){dp[i] = dp[i + 1];continue;}
		dp[i] = Mod(dp[i + 1] + w[a[i]]);
		w[a[i]] = dp[i];
	}
	cout << dp[1] << endl;
	return 0;
}
