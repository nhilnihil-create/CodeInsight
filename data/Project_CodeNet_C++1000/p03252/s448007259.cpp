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
	string s, t;
	cin >> s >> t;
	unordered_map<char, char> um1, um2;
	int n = s.size();
	for (int i = 0; i < n; i++) {
		if (um1.find(s[i]) == um1.end()) {
			um1[s[i]] = t[i];
		} else {
			if (um1[s[i]] != t[i]) {
				cout << "No" << endl;
				return 0;
			}
		}
		if (um2.find(t[i]) == um2.end()) {
			um2[t[i]] = s[i];
		} else {
			if (um2[t[i]] != s[i]) {
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
}
