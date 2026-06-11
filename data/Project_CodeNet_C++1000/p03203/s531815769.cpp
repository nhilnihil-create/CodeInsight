#include <bits/stdc++.h>
using i64 = long long;
using std::cout;
using std::endl;
using std::cin;

int main() {
	int h, w, n; scanf("%d%d%d", &h, &w, &n);
	std::vector<int> a(n), b(n);
	std::vector<std::pair<int, int>> latte;
	for(int i = 0; i < n; i++) {
		scanf("%d%d", &a[i], &b[i]);
		latte.push_back({b[i], a[i]});
	}
	sort(begin(latte), end(latte));
	
	int c = 0;
	std::vector<int> vec(n, 1 << 30);
	for(int i = 0; i < n; i++) {
		int A = latte[i].second, B = latte[i].first;
		if(A - B != c) continue;
		vec[c++] = B;
	}
	int ans = h;
	for(int i = 0; i < n; i++) {
		int k = upper_bound(begin(vec), end(vec), b[i]) - begin(vec);
		if(a[i] - b[i] < k) continue;
		ans = std::min(ans, a[i] - 1);
	}
	printf("%d\n", ans);
	return 0;
}
