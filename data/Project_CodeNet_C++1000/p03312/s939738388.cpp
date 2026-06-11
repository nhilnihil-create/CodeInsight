#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
const long long INF = 1e18;

int a[N];
long long sum[N];
long long ans;
int n;

void update(int pos, int d1, int d2){
	long long maxx, minx;
	maxx = max(sum[d1], sum[pos] - sum[d1]);
	maxx = max(maxx, sum[d2] - sum[pos]);
	maxx = max(maxx, sum[n] - sum[d2]);
	minx = min(sum[d1], sum[pos] - sum[d1]);
	minx = min(minx, sum[d2] - sum[pos]);
	minx = min(minx, sum[n] - sum[d2]);
	ans = min(ans, maxx - minx);
}

int main(){
	int d1, d2;
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) scanf("%d",&a[i]);
	sum[0] = 0;
	for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
	ans = INF;
	for (int i = 2; i <= n - 2; i++){
		d1 = lower_bound(sum + 1, sum + i + 1, sum[i] / 2) - sum;
		d2 = lower_bound(sum + i + 2, sum + n + 1, (sum[n] + sum[i]) / 2) - sum;
		if (d1 > 1 && d2 > i) update(i, d1 - 1, d2 - 1);
		if (d1 > 1 && d2 < n) update(i, d1 - 1, d2);
		if (d1 < i && d2 > i) update(i, d1, d2 - 1);
		if (d1 < i && d2 < n) update(i, d1, d2);
	}
	printf("%lld\n", ans);
	return 0;
}