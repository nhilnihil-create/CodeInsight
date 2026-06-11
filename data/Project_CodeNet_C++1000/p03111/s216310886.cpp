#include <bits/stdc++.h>
using namespace std;

int n, a, b, c, len[8], ans = 2e9, cost, bamboo;

int main() {
	cin >> n >> a >> b >> c;
	for (int i = 0; i < n; i++)
		cin >> len[i];
	for (int i = 1; i < 1 << n; i++)
		for (int j = 1; j < 1 << n; j++)
			for (int k = 1; k < 1 << n; k++) {
				if (i & j || j & k || k & i)
					continue;
				cost = (__builtin_popcount(i) + __builtin_popcount(j)
						+ __builtin_popcount(k) - 3) * 10;
				bamboo = 0;
				for (int l = 0, bit = i; bit; l++, bit >>= 1)
					if (bit & 1)
						bamboo += len[l];
				cost += abs(bamboo - a);
				bamboo = 0;
				for (int l = 0, bit = j; bit; l++, bit >>= 1)
					if (bit & 1)
						bamboo += len[l];
				cost += abs(bamboo - b);
				bamboo = 0;
				for (int l = 0, bit = k; bit; l++, bit >>= 1)
					if (bit & 1)
						bamboo += len[l];
				cost += abs(bamboo - c);
				ans = min(ans, cost);
			}
	cout << ans << endl;
}
