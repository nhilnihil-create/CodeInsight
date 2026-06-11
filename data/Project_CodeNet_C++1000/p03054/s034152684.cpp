#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}
int64_t rll() {
	long long n;
	scanf("%lld", &n);
	return n;
}

int main() {
	int h = ri();
	int w = ri();
	int n = ri();
	int s_1 = ri(), s_2 = ri();
	std::string s, t;
	std::cin >> s >> t;
	
	int l = 1, r = w;
	bool res = true;
	for (int i = n - 1; i >= 0; i--) {
		// aoki
		if (t[i] == 'L' && r < w) r++;
		else if (t[i] == 'R' && l > 1) l--;
		if (r < l) {
			res = false;
			break;
		}
		if (s[i] == 'L') l++;
		else if (s[i] == 'R') r--;
		if (r < l) {
			res = false;
			break;
		}
		// std::cerr << "l:" << l << " r:" << r << std::endl;
	}
	// std::cerr << std::endl;
	if (s_2 < l || s_2 > r) res = false;
	l = 1, r = h;
	for (int i = n - 1; i >= 0; i--) {
		// aoki
		if (t[i] == 'U' && r < h) r++;
		else if (t[i] == 'D' && l > 1) l--;
		if (r < l) {
			res = false;
			break;
		}
		if (s[i] == 'U') l++;
		else if (s[i] == 'D') r--;
		if (r < l) {
			res = false;
			break;
		}
		// std::cerr << "l:" << l << " r:" << r << std::endl;
	}
	if (s_1 < l || s_1 > r) res = false;
	std::cout << (res ? "YES" : "NO") << std::endl;
	
	return 0;
}
