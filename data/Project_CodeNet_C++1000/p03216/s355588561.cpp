#include <bits/stdc++.h>
using namespace std;

char s[1000010];
int sum[1000010][2];
int n, m;

long long solve(int k){
	int l = 1, r = k;
	long long tot = 0;
	for (int i = 1; i <= k; i++){
		tot += (s[i] == 'C' ? sum[i][0] : 0);
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++){
		if (s[i] == 'D') ans += tot;
		if (s[i] == 'M') tot -= sum[min(i + k - 1, n)][1] - sum[i - 1][1];
		if (i + k <= n && s[i + k] == 'C') tot += sum[i + k][0] - sum[i][0];
	}
	return ans;
}

int main(){
	scanf("%d", &n);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i++){
		sum[i][0] = sum[i - 1][0] + (s[i] == 'M');
		sum[i][1] = sum[i - 1][1] + (s[i] == 'C');
	}
	int m; scanf("%d", &m);
	for (int i = 0; i < m; i++){
		int k; scanf("%d", &k);
		printf("%lld\n", solve(k));
	}
	return 0;
}
