#include <stdio.h>
#include <utility>
#include <algorithm>

using namespace std;

typedef long long lli;
typedef pair<lli, lli> ip;
typedef pair<ip, ip> q;

lli a[200001], s[200001];
int n;

q f(int l, int r) {
	if (l + 1 == r) return q(ip(a[l], a[r]), ip(a[l], a[r]));
	if (a[l] >= s[r] - s[l]) return q(ip(a[l], s[r] - s[l]), ip(a[l] + a[l + 1], s[r] - s[l + 1]));
	int lo = l, hi = r - 1;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		if (s[mid] - s[l - 1] < s[r] - s[mid]) lo = mid;
		else hi = mid;
	}
	return q(ip(s[lo] - s[l - 1], s[r] - s[lo]), ip(s[lo + 1] - s[l - 1], s[r] - s[lo + 1]));
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		s[i] = s[i - 1] + a[i];
	}
	lli res = (1LL << 60);
	for (int i = 2; i <= n - 2; i++) {
		q t1 = f(1, i), t2 = f(i + 1, n);
		lli r1[2][2] = {
			{t1.first.first, t1.first.second},
			{t1.second.first, t1.second.second}
		}, r2[2][2] = {
			{t2.first.first, t2.first.second},
			{t2.second.first, t2.second.second}
		};
		for (int u = 0; u < 2; u++) {
			for (int v = 0; v < 2; v++) {
				lli A[4] = { r1[u][0],r1[u][1],r2[v][0],r2[v][1] };
				sort(A, A + 4);
				lli dif = A[3] - A[0];
				if (dif < res) res = dif;
			}
		}
	}
	printf("%lld\n", res);
	return 0;
}