#include <bits/stdc++.h>

using namespace std;

#define intt long long
#define FAST ios_base::sync_with_stdio(0); cin.tie(0);

const int N = 100005;

int n, m;

int main() {

	FAST;

	cin >> n >> m;
	int g = 1;
	for (int i = 1; i * i <= m; i ++) {
		if (m % i == 0) {
			if (i >= n) {
				g = max(g, m / i);
			}
			if (m / i >= n) {
				g = max(g, i);
			}
		}
	}
	cout << g << '\n';
	return 0;
}