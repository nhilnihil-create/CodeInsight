#include <iostream> 
#include <vector>
#include <cstring>
#include <algorithm>


int main() {
	using namespace std;
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> dp(n + 1, vector<int> (10,-1e9));
	vector<int> mapped = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
	vector<int> v(m);
	for (int i = 0; i < m; ++i) {
		cin >> v[i];
	}
	
	for (int i = 0; i < 10; ++i) dp[0][i] = 0;
	
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j <= n; ++j) {
			int x = mapped[v[i]];
			if (j >= x) {
				if (1 + dp[j - x][0] >= dp[j][0]) {
					if (1 + dp[j - x][0] > dp[j][0]) {
						dp[j] = dp[j - x];
						dp[j][0]++;
						dp[j][v[i]]++;
					}else {
						vector<int> d1 = dp[j - x];
						d1[0]++;
						d1[v[i]]++;
						vector<int> d2 = dp[j];
						reverse(d1.begin(), d1.end()); 
						reverse(d2.begin(), d2.end()); 
						if (d1 > d2) {
							reverse(d1.begin(), d1.end());
							dp[j] = d1;
						} 
					}
				}
			}
		} 
	}
	
	for (int i = 9; i > 0; --i) {
		for (int j = 0; j < dp[n][i]; ++j) {
			cout << i;
		}
	}
}






