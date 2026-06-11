#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long lli;

int a[100001], b[100001], n;

lli dnc(int l, int r) {
	if (l > r) return 0;
	if (l == r) return b[l] > 0;
	int mid = (l + r) / 2;
	lli ret = dnc(l, mid) + dnc(mid + 1, r);
	vector<int> L, R;
	int cur = 0;
	for (int i = mid; i >= l; i--) {
		cur += b[i];
		L.push_back(cur);
	}
	cur = 0;
	for (int i = mid + 1; i <= r; i++) {
		cur += b[i];
		R.push_back(cur);
	}
	sort(L.begin(), L.end());
	for (int i = 0; i < R.size(); i++) {
		if (L[0] >= -R[i]) ret += L.size();
		else if (L.back() < -R[i]) continue;
		else{
			int lo = 0, hi = L.size() - 1;
			while (lo + 1 < hi) {
				int mid = (lo + hi) / 2;
				if (L[mid] >= -R[i]) hi = mid;
				else lo = mid;
			}
			ret += L.size() - hi;
		}
	}
	return ret;
}

lli f(int k) {
	for (int i = 1; i <= n; i++) {
		if (a[i] < k) b[i] = -1;
		else b[i] = 1;
	}
	return dnc(1, n);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	lli C = (lli)n*(n + 1LL) / 2;
	int lo = 1, hi = 1000000001;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		if (f(mid) >= (C + 1) / 2) lo = mid;
		else hi = mid;
	}
	printf("%d\n", lo);
	return 0;
}