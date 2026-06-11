#include <bits/stdc++.h>
using namespace std;
int n, a[223123];
map<int, int> mp;

bool chk(int x) {
	mp.clear();
	for (int i = 1; i <= n; ++i)
		if (a[i] <= a[i - 1]) {
			int p = a[i];
			while (!mp.empty()) {
				map<int, int>::iterator it = --mp.end();
				if (it -> first > p) mp.erase(it);
				else break;
			}
			while (mp[p] == x - 1) {
				mp[p] = 0; --p;
				if (!p) return 0;
			}
			++mp[p];
		}
	return 1;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	bool fd = 1;
	for (int i = 1; i < n; ++i)
		if (a[i] >= a[i + 1]) {
			fd = 0; break;
		}
	if (fd) {
		printf("1"); return 0;
	}
	int l = 2, r = n;
	while (l != r) {
		int mid = (l + r) >> 1;
		if (chk(mid)) r = mid;
		else l = mid + 1;
	}
	printf("%d", l);
}
