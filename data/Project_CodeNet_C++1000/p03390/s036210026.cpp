/*
	atcoder ARC094
	D Worst Case
*/
#include <bits/stdc++.h>
typedef long long ll;

inline void up(int &x, int y) { x < y ? x = y : 0; }
inline void down(int &x, int y) { x > y ? x = y : 0; }
inline int max(const int x, const int y) { return x > y ? x : y; }
inline int min(const int x, const int y) { return x < y ? x : y; }

inline void swap(ll &x, ll &y) { x ^= y ^= x ^= y; }

inline ll calc(ll A, ll B) {
	if (A > B) swap(A, B);
	if (A == B) return A * 2 - 2;
	ll C = sqrt(A * B);
	if (C * C == A * B) --C;
	if (C * (C + 1) < A * B) return C * 2 - 1;
	else return 2 * C - 2;
}
int t;
ll A, B;
int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(0);
    for (std::cin >> t; t; --t) std::cin >> A >> B, std::cout << calc(A, B) << '\n';
	return 0;
}
