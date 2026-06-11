#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

long long int dp[21005];

int N;
int w[1003], s[1003];
long long int v[1003];

vector<pair<int, pair<int, long long int>> > V;

int main(void) {

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> w[i] >> s[i] >> v[i];
		V.push_back(make_pair(s[i]+w[i], make_pair(w[i], v[i])));
	}

	sort(V.begin(), V.end());

	for (int i = 1; i <= N; i++) {
		int vs = V[i - 1].first-V[i-1].second.first;
		int vw = V[i - 1].second.first;

		long long int val = V[i - 1].second.second;
		for (int W = 20000; W >= 0; W--) {
			if (dp[W] > 0 && W <= vs) { dp[W + vw] = max(dp[W + vw], dp[W] + val); }
		}
		dp[vw] = max(dp[vw], val);
	}

	long long int ans = 0;

	for (int W = 20000; W >= 0; W--) {
		ans = max(ans, dp[W]);
	}

	cout << ans << endl;

	return 0;
}