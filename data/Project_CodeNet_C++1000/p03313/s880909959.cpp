#include<bits/stdc++.h>
#define ff(i, x, y) for(int i = x;i <= y;i++)
using namespace std;
typedef long long ll;
int n, sum, a[300010], dp[300010][2];
int main() {
	scanf("%d", &n);
	ff(i, 0, (1 << n) - 1) {
		scanf("%d", &a[i]);
	}
	dp[0][0] = 0;
	dp[0][1] = 0;
	if(a[1] > a[0])
	dp[1][0] = 1;
	else
	dp[1][1] = 1;
	ff(i, 2, (1 << n) - 1) {
		int id0, id1;
		if(a[0] > a[i]) {
			id0 = 0;
			id1 = i;
		}
		else {
			id0 = i;
			id1 = 0;
		}
		ff(bit, 0, n - 1) {
			if(i & (1 << bit)) {
				if(a[dp[i ^ (1 << bit)][1]] >= a[id0] && id0 != dp[i ^ (1 << bit)][1]) {
					id1 = id0;
					id0 = dp[i ^ (1 << bit)][1];
				}
				else if(a[dp[i ^ (1 << bit)][1]] > a[id1] && id0 != dp[i ^ (1 << bit)][1])
					id1 = dp[i ^ (1 << bit)][1];
				if(a[dp[i ^ (1 << bit)][0]] >= a[id0] && id0 != dp[i ^ (1 << bit)][0]) {
					id1 = id0;
					id0 = dp[i ^ (1 << bit)][0];
				}
				else if(a[dp[i ^ (1 << bit)][0]] > a[id1] && id0 != dp[i ^ (1 << bit)][0])
					id1 = dp[i ^ (1 << bit)][0];
			}
		}
		dp[i][0] = id0;
		dp[i][1] = id1;
	}
	int ans = 0;
	ff(i, 1, (1 << n) - 1) {
		ans = max(a[dp[i][0]] + a[dp[i][1]], ans);
		printf("%d\n", ans);
	}
	return 0;
}