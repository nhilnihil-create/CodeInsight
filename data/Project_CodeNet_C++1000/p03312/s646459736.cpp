#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
int a[200002];
ll sum[200002];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		sum[i] = sum[i-1]+a[i];
	}
	ll ans = 1e18;
	int l = 1, r = 3;
	for (int i = 2; i <= n-2; i++) {
		while (abs(sum[i]-sum[l]-sum[l]) > abs(sum[i]-sum[l+1]-sum[l+1])) {
			l++;
		}
		while (abs(sum[n]-sum[r]-(sum[r]-sum[i])) > abs(sum[n]-sum[r+1]-(sum[r+1]-sum[i]))) {
			r++;
		}
		ans = min(ans, max({ sum[i]-sum[l],sum[l],sum[n]-sum[r],sum[r]-sum[i] })-min({ sum[i]-sum[l],sum[l],sum[n]-sum[r],sum[r]-sum[i] }));
	}
	
	printf("%lld\n", ans);
	
	return 0;
}