#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
const int maxn = 2e5 + 10;

int n, a[maxn], p, flag = 1;
bool check(int k) {
	std::map<int, int> M; M.clear();
	for (int i = 1; i <= n; ++i) if (a[i] <= a[i - 1]) {
		while (!M.empty() && M.rbegin() -> first > a[i]) M.erase(--M.end());
		for (p = a[i]; p && ++M[p] == k; --p) M[p] = 0;
		if (!p) return false;
	}
	return true;
}

int main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
	std::cin >> n;
	for (int i = 1; i <= n; ++i) std::cin >> a[i], flag &= a[i] > a[i - 1];
	if (flag) return std::cout << "1\n", 0;
	int l = 2, r = n, ans = n;
	while (l <= r) {
		int mid = l + r >> 1;
		if (check(mid)) r = mid - 1, ans = mid;
		else l = mid + 1;
	}
	std::cout << ans << '\n';
	return 0;
}
