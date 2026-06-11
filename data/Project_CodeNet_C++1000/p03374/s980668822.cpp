#include <bits/stdc++.h>
using namespace std;

typedef long long arr[110000];

arr v, d, rev, pred, sufd, sufv, maxsuf, maxpre;
long long n, c;

int main() {
	cin >> n >> c;
	for (int i = 1; i <= n; i++)
		scanf("%lld%lld", &pred[i], &v[i]);
	for (int i = 1; i <= n; i++)
		rev[i] = rev[i - 1] + v[i];
	sufd[n] = c - pred[n];
	sufv[n] = v[n];
	for (int i = n - 1; i >= 1; i--) {
		sufd[i] = c - pred[i];
		sufv[i] = sufv[i + 1] + v[i]; 
	}
	for (int i = 1; i <= n; i++)
		if (rev[i] - pred[i] > maxpre[i - 1])
			maxpre[i] = rev[i] - pred[i];
		else maxpre[i] = maxpre[i - 1];
	maxsuf[n + 1] = 0;
	for (int i = n; i >= 1; i--)
		if (sufv[i] - sufd[i] > maxsuf[i + 1])
			maxsuf[i] = sufv[i] - sufd[i];
		else maxsuf[i] = maxsuf[i + 1];
//	for (int i = 1; i <= n; i++) {
//		cout << rev[i] << " " << pred[i] << " " << maxpre[i] << endl;
//	}
	long long ans = 0;
	ans = max(ans, max(maxsuf[1], maxpre[n]));
	for (int i = 1; i <= n; i++)
		ans = max(ans, max(rev[i] - pred[i] - pred[i] + maxsuf[i + 1], maxpre[i] + sufv[i + 1] - sufd[i + 1] - sufd[i + 1]));
	cout << ans;
	return 0;
}