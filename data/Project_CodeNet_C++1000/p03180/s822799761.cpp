#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int N = 12 + 5;

ll dp[(1 << N)], ans[(1 << N)];
int n, a[N][N];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);	
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	for (int mask = 0; mask < (1 << n); mask++) {
		vector <int> vec;
		for (int i = 0; i < n; i++)
			if(mask & (1 << i))
				vec.push_back(i);
		for (int i = 0; i < vec.size(); i++)
			for (int j = i + 1; j < vec.size(); j++)
				ans[mask] += a[vec[i]][vec[j]];
	}
	dp[0] = 0;
	for (int mask = 1; mask < (1 << n); mask++) {
		for (int submask = mask; submask; submask = (submask - 1) & mask)
			dp[mask] = max(dp[mask], ans[submask] + dp[mask ^ submask]);
	}
	cout << dp[(1 << n) - 1] << "\n";
}
