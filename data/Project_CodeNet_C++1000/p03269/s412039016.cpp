#include <bits/stdc++.h>
#define R register

const int MN = 100;

int L;

int m;

int x[MN], y[MN], vl[MN];

int main() {
	std::ios::sync_with_stdio(false);

	std::cin >> L;
	for (R int i = 2; i < 20; ++i)
		x[++m] = i, y[m] = i + 1, vl[m] = 0,
		x[++m] = i, y[m] = i + 1, vl[m] = 1 << 19 - i;

	for (R int i = 0, s = 0; (1 << i) <= L; ++i)
		if ((L >> i) & 1) {
			s += 1 << i;
			if (i == 19) {
				x[++m] = 1, y[m] = 2, vl[m] = 0;
				x[++m] = 1, y[m] = 2, vl[m] = 1 << 18;
				continue;
			}
			x[++m] = 1, y[m] = 20 - i, vl[m] = L - s;
		}
	
	std::cout << 20 << " " << m << std::endl;
	for (R int i = 1; i <= m; ++i) 
		std::cout << x[i] << " " << y[i] << " " << vl[i] << std::endl;
	return 0;
}