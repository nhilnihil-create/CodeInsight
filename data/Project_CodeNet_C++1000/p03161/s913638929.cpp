#include <iostream>
#include <vector>

using namespace std;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const int INF = 1 << 30;

int main()
{
	int n;
	int k;
	cin >> n >> k;
	vector<int> h(n);
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}

	vector<int> dp(n + k, INF);
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= k; j++) {
			chmin(dp[i + j], dp[i] + abs(h[i] - h[i + j]));
		}
	}

	cout << dp[n - 1] << endl;

	return 0;
}