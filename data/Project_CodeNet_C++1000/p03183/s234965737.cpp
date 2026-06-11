#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3+10;
const int maxs = 2e4+10;

int n;
long long int dp[maxn][maxs], w[maxn], s[maxn], v[maxn], d[maxn];

bool comp(int i, int j){
	return s[i] < s[j];
}

int main(){
	cin >> n;
	for (int i = 0; i < n; i++){
		scanf("%d%d%d", &w[i], &s[i], &v[i]);
		s[i] += w[i];
		d[i] = i;
	}

	sort(d, d+n, comp);

	for (int i = w[d[0]]; i < maxs; i++)
		dp[0][i] = v[d[0]];

	for (int i = 1; i < n; i++){
		for (int j = 0; j < maxs; j++){
			dp[i][j] = dp[i-1][j];
			if (w[d[i]] <= j){
				dp[i][j] = max(dp[i][j], dp[i-1][min(j-w[d[i]], s[d[i]]-w[d[i]])] + v[d[i]]);
			}
		}
	}

	cout << dp[n-1][maxs-1] << endl;
	return 0;
}
