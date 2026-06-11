#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int n, x;
int a[MAXN];
long long sum[MAXN];

int main()
{
	scanf("%d%d", &n, &x);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		sum[i] = sum[i-1]+a[i];
	}
	long long ans = 1e18;
	for (int i = 1; i <= n; i++) {
		__int128 cur = 1ll*n*x+5ll*(sum[n]-sum[i-1])+(n-i+1ll)*x;
		int k = n-i+1;
		for (int j = i-1, d = 5; j >= 1; j -= k, d += 2) {
			if (j-k < 1) {
				cur += 1ll*d*sum[j];
				break;
			}
			cur += 1ll*d*(sum[j]-sum[j-k]);
		}
		ans = min((__int128)ans, cur);
	}
	cout << ans << endl;
	return 0; 
}
