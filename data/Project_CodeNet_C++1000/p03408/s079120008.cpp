#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <deque>
#include <cstdio>
#include <set>
#include <map>
#include <bitset>
#include <stack>
using namespace std;
int main() {
	int n, m;
	cin >> n;
	vector<string> vec;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		vec.emplace_back(s);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		if (!vec.empty()) {
			for (int i = 0; i < vec.size(); i++) {
				if (s == vec[i]) {
					vec.erase(vec.begin() + i);
					break;
				}
			}
		}
	}
	if (vec.empty()) {
		cout << "0" << endl;
		return 0;
	}
	sort(vec.begin(), vec.end());
	int co = 1, ma = 0;
	for (int i = 0; i < vec.size() - 1; i++) {
		if (vec[i] != vec[i + 1]) {
			if (ma < co) {
				ma = co;
			}
			co = 1;
		}
		else {
			co++;
		}
	}
	if (ma < co) {
		ma = co;
	}
	cout << ma << endl;
	return 0;
}
