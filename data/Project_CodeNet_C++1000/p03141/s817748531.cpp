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
#include <cctype>
using namespace std;
int main() {
	vector<pair<long long,pair<long long, long long>>> vec, vec1;
	set<pair<long long, long long>> st;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		long long a, b;
		cin >> a >> b;
		vec.emplace_back(make_pair(a+b,make_pair(a, b)));
	}
	sort(vec.begin(), vec.end());
	long long ta = 0, ao = 0;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			ta += vec[n - i - 1].second.first;
		}
		else {
			ao += vec[n - i - 1].second.second;
		}
	}
	cout << ta - ao << endl;
	return 0;
}