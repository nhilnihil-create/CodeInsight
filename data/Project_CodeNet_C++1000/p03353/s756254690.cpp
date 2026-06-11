#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <string>
#include <set>

using namespace std;

int main() {
	string s;
	int k;
	cin >> s >> k;

	set<string> subs;
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j < s.size(); j++) {
			auto t = s.substr(j, i);
			subs.insert(t);
		}
	}

	auto it = subs.begin();
	it = next(it, k - 1);
	cout << *it << endl;
	return 0;
}
