#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>
#include <chrono>
#include <random>
#include <functional>

using namespace std;

const int INF = 1e9 + 239;

int can(vector<int> a, int l, int r, int q, int k) {
	int n = (int)a.size();
	int c = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] < l) {
			continue;
		} else {
			int p = i;
			int cnt_less_r = 0;
			if (a[i] <= r) cnt_less_r++;
			vector<int> sb = {a[i]};
			while (p + 1 < n && a[p + 1] >= l) {
				if (a[p + 1] <= r) {
					cnt_less_r++;
				}
				sb.push_back(a[p + 1]);
				p++;
			}
			int len = p - i + 1;
			if (len >= k) {
				c += min(len - k + 1, cnt_less_r);
			}
			i = p;
		}
	}
	return c >= q;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n, k, q;
	cin >> n >> k >> q;
	if (q == 1) {
		cout << 0 << endl;
		exit(0);
	}
	vector<int> a(n);
	for (auto &t : a) {
		cin >> t;
	}	
	int ans = INF;
	vector<int> sn = a;
	sort(sn.begin(), sn.end());
	for (int i = 0; i < n; i++) {
		vector<int> na = a;
		na.erase(na.begin() + i);
		{
			int l = -1;
			int r = n - 1;
			while (r - l > 1) {
				int m = (r + l) >> 1;
				if (can(na, a[i], sn[m], q - 1, k)) r = m;
				else l = m;
			}
			if (can(na, a[i], sn[r], q - 1, k)) ans = min(ans, sn[r] - a[i]);
		}
	}
	cout << ans << '\n';
}
