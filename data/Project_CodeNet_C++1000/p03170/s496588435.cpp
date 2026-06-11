#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	vector<int> a(n);
	for (int& x : a) {
		scanf("%d", &x);
	}
	vector<bool> dp(k + 1);
	for (int stones = 0; stones <= k; ++stones) {
		for (int x : a) {
			if (stones >= x && !dp[stones - x]) {
				dp[stones] = true;
			}
		}
	}

	puts(dp[k] ? "First" : "Second");
	return 0;
}