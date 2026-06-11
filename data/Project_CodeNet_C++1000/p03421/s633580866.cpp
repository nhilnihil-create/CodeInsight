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

#define int long long

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, a, b;
	cin >> n >> a >> b;
	if (a + b - 1 <= n && n <= a * b) {
		int cn = a * b;
		vector<int> bl(b);
		int pnt = cn - a;
		for (int i = 0; i < b; i++) {
			bl[i] = pnt;
			pnt -= a;
		}
		vector<int> ans;
		int delta = cn - n;
		for (int i = 0; i < b; i++) {
			int skip = min(delta, a - 1);
			if (i == 0) skip = 0;
			delta -= skip;
			for (int j = skip; j < a; j++) {
				ans.push_back(bl[i] + j);
			}
		}
		{
			vector<int> v = ans;
			sort(v.begin(), v.end());
			for (auto &t : ans) {
				t = lower_bound(v.begin(), v.end(), t) - v.begin();
			}
		}
		for (auto t : ans) {
			cout << t + 1 << ' ';
		}
		cout << '\n';
	} else {
		cout << -1 << endl;
	}
}
