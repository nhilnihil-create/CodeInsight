#include <bits/stdc++.h>

using ll = long long;
using ld = long double;
constexpr ll inf = static_cast<ll>(1e17);
constexpr ll mod = static_cast<ll>(1e9 + 7);

std::string s;
int main() {
	std::cin >> s;

	int a = 0, b = 0, c = 0;
	for (int i = 0, end = s.size(); i < end; ++i) {
		auto ss = s[i];

		switch (ss)
		{
		case 'a':
			++a;
			break;
		case 'b':
			++b;
			break;
		default:
			++c;
			break;
		}
	}

	auto m = std::max({ std::abs(a - b),std::abs(b - c),std::abs(c - a) });
	if (m > 1)
		std::cout << "NO" << std::endl;
	else
		std::cout << "YES" << std::endl;
	return 0;
}
