#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define dunk(a) cout << (a) << endl
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	map<pair<int, int>, bool> r;
	rep(i, 3) {
		int a, b; cin >> a >> b;
		a--; b--;
		r[make_pair(a, b)] = true;
		r[make_pair(b, a)] = true;
	}
	//0-indexed

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (r[make_pair(i, j)] || r[make_pair(j, i)]) {
				for (int k = 0; k < 4; ++k) {
					if (k == i) continue;
					if (r[make_pair(j, k)] || r[make_pair(k, j)]) {
						for (int l = 0; l < 4; ++l) {
							if (l == i || l == j) continue;
							if (r[make_pair(k, l)] || r[make_pair(l, k)]) {
								puts("YES");
								return 0;

							}
						}
					}
				}
			}
		}
	}

	puts("NO");

	return 0;
}