#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <functional>
#include <bitset>
#include <cassert>
#include <random>
using namespace std;
using ll = long long;


int main() {
	int m, k; cin >> m >> k;
	if ((1 << m) <= k) {
		cout << -1 << endl;
		return 0;
	}
	if (k == 0) {
		for (int i = 0; i < (1 << m); i++) {
			cout << i << " " << i << " \n"[i == (1 << m) - 1];
		}
		return 0;
	}
	if (m == 1 && k == 1) {
		cout << -1 << endl; 
		return 0;
	}
	vector<int> v;
	for (int i = 0; i < (1 << m); i++) {
		if (i == k) continue;
		v.push_back(i);
	}
	vector<int> ans;
	ans.push_back(k);
	for (int i : v) ans.push_back(i);
	ans.push_back(k);
	reverse(v.begin(), v.end());
	for (int i : v) ans.push_back(i);
	for (int i = 0; i < (1 << (m + 1)); i++) {
		cout << ans[i] << " \n"[i == (1 << (m + 1)) - 1];
	}
	return 0;
}
