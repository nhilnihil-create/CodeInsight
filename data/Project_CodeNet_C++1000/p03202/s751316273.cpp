#include <bits/stdc++.h>

const int N = 200005;

int n, a[N];
std::map<int, int> str;

bool check(int m) {
	for (int i = 1; i <= n; ++i) {
		if (a[i] > a[i - 1]) str[a[i - 1] + 1] = 1;
		else {
			std::map<int, int>::iterator it = str.upper_bound(a[i]);
			while (it != str.end()) str.erase(it++);
			for (it = --str.end(); ; --it) {
				if (it->second < m) {
					int c = it->second + 1;
					auto nxt = it; ++nxt;
					int b = nxt == str.end() ? a[i] : nxt->first - 1;
					str[b] = c; break;
				} else {
					it->second = 1;
				}
				if (it == str.begin()) return 0;
			}
		}
	}
	return 1;
}
int main() {
	std::ios::sync_with_stdio(0), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1; i <= n; ++i) std::cin >> a[i];
	int l = 1, r = n, ans = -1;
	while (l <= r) {
		int mid = l + r >> 1;
		if (check(mid)) r = mid - 1, ans = mid;
		else l = mid + 1;
	}
	std::cout << ans << '\n';
	return 0;
}
