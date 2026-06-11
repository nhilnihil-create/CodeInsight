#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
#define all(x) x.begin(), x.end()
#define x first
#define y second
#define mp make_pair
#define mt make_tuple

const int N = 1e6 + 10;

int n;
int a[N];
map<int, int> s;

bool check(int k) {
	s.clear();
	for (int i = 1; i < n; ++i) {
		if (a[i - 1] < a[i]) {
			continue;
		} else {
			int j = a[i];
			while (s.size() && s.rbegin()->x > j) {
				s.erase(s.rbegin()->x);
			}
			if (s[j] == 0) {
				if (k == 1) {
					return false;
				}
				s[j] = 1;
				continue;
			}
			while (j > 0) {
				if (s[j] + 1 < k) {
					++s[j];
					break;
				} else {
					s[j] = 0;
					--j;
				}
			}
			if (!j) {
				return false;
			}
		}
	}
	return true;
}

signed main() {
#ifdef LC
	assert(freopen("input.txt", "r", stdin));
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int lef = 0, rig = n;
	while (rig - lef > 1) {
		int mid = (lef + rig) / 2;
		if (check(mid)) {
			rig = mid;
		} else {
			lef = mid;
		}
	}
	cout << rig << "\n";
	return 0;
}
