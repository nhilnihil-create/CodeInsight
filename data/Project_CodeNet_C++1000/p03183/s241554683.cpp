#include <bits/stdc++.h>
using namespace std;

int n;
int w[1055], s[1055];
int v[1055];

long long dp[20055];

int main() {
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> w[i] >> s[i] >> v[i];
	}
	
	vector<int> vs(n);
	
	for (int i = 0; i < n; i++) {
		vs[i] = i;
	}
	
	// sum(w[1..i - 1]) <= s[i]
	
	sort(vs.begin(), vs.end(), [&] (int v, int u) {
		return s[v] - w[u] < s[u] - w[v];
	});
	
	for (int i = 0; i < n; i++) {
		int u = vs[i];
		
		for (int j = s[u]; j >= 0; j--) {
			dp[j + w[u]] = max(dp[j + w[u]], dp[j] + v[u]);
		}
	}
	
	cout << *max_element(dp, dp + (int)2e4 + 1);
}
