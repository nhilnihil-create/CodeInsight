#include <bits/stdc++.h>

int n, k, idx, lst, p = 1;
std::string s;

int main() {
	std::ios::sync_with_stdio(0), std::cin.tie(0);
	std::cin >> s, n = s.size(), s = '0' + s;
	if (s != std::string(s.rbegin(), s.rend()) || s[1] != '1')
		return std::cout << -1 << '\n', 0;
	k = std::count(s.begin(), s.end(), '1'), idx = k + 1;
	for (int i = 1; i <= k; ++i)
		std::cout << i << ' ' << i + 1 << '\n';
	for (int i = 1; i <= n; ++i) if (s[i] == '1') {
		for (int j = 1; j < i - lst; ++j)
			std::cout << p << ' ' << ++idx << '\n';
		++p, lst = i;
	}
	return 0;
}