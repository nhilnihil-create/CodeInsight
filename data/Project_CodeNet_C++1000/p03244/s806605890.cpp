#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;


int main() {
	int n;
	cin >> n;
	vector<int> v(n, 0);
	
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	unordered_map<int, int> um;
	for (int i = 0; i < n; i += 2) {
		um[v[i]]++;
	}
	int c1 = n / 2 + n % 2;
	set<pair<int, int>> s1, s2;
	for (auto p : um) {
		s1.insert(make_pair(c1 - p.second, p.first));
	}
	um.clear();
	int c2 = n / 2;
	for (int i = 1; i < n; i += 2) {
		um[v[i]]++;
	}
	for (auto p : um) {
		s2.insert(make_pair(c2 - p.second, p.first));
	}

	int res = min(s1.begin()->first + c2, s2.begin()->first + c1);
	c1 = 0, c2 = 0;
	for (auto it1 = s1.begin(); it1 != s1.end() && c1 < 2; it1++ ) {
		c2 = 0;
		for (auto it2 = s2.begin(); it2 != s2.end() && c2 < 2; it2++) {
			if (it1->second != it2->second) {
				res = min(res, it1->first + it2->first);
			}
			c2++;
		}
		c1++;
	}
	cout << res << endl;
}
