#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int n, a[N];

bool check(int mid) {
	map<int, int> b;
	for (int i = 2; i <= n; ++i) {
		while (!b.empty() && b.rbegin()->first >= a[i])
			b.erase(--b.end());
		if (a[i] <= a[i - 1]) {
			++b[a[i] - 1];
			for (int j = a[i] - 1; b.count(j) && b[j] == mid; --j) {
				b.erase(j);
				if (j == 0) return false;
				++b[j - 1];
			}
		}
	}
	return true;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", a + i);
	bool flag = true;
	for (int i = 2; i <= n; ++i)
		flag &= a[i] > a[i - 1];
	if (flag) return puts("1"), 0;
	int l = 2, r = n;
	while (l < r) {
		int mid = l + r >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	printf("%d\n", r);
	return 0;
}
