/*
	atcoder ARC094
	E Tozan and Gezan
*/
#include <bits/stdc++.h>
typedef long long ll;
const int N = 2e5 + 5;

inline void up(int &x, int y) { x < y ? x = y : 0; }
inline void down(int &x, int y) { x > y ? x = y : 0; }
inline int max(const int x, const int y) { return x > y ? x : y; }
inline int min(const int x, const int y) { return x < y ? x : y; }

int n, a[N], b[N];
inline bool equal() {
	for (int i = 1; i <= n; ++i) 
		if (a[i] != b[i]) return false;
	return true;
}

inline ll play() {
	int min = 1000000010;
	ll s0 = 0;
	for (int i = 1; i <= n; ++i) s0 += a[i];
	for (int i = 1; i <= n; ++i)
		if (a[i] > b[i]) down(min, b[i]);
	return s0 - min;
}
int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(0);
    std::cin >> n;
    for (int i = 1; i <= n; ++i) std::cin >> a[i] >> b[i];
    if (equal()) return std::cout << 0 << '\n', 0;
    std::cout << play() << '\n';
	return 0;
}
