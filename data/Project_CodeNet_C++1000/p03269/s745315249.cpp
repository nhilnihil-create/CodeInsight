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

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);	

	int l;
	cin >> l;
	vector<tuple<int, int, int>> ans;
	int tot = 0;
	for (int i = 0; l > 1; i++) {
		if (l & 1) {
			ans.push_back(make_tuple(i, -1, l - 1));
			l--;
		} 
		if (l > 0) {
			ans.push_back(make_tuple(i, i + 1, 0));
			ans.push_back(make_tuple(i, i + 1, l / 2));
			l /= 2;
		}
		tot = i + 1;
	}
	cout << tot + 1 << ' ' << ans.size() << endl;
	for (auto t : ans) {
		int u, v, c;
		tie(u, v, c) = t;
		if (v == -1) v = tot;
		cout << u + 1 << ' ' << v + 1 << ' ' << c << endl;
	}
}