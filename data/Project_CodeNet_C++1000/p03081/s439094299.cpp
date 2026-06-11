#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

#define INF 2140000000
#define MOD 1000000007

bool fall(string s, vector<pair<char,char> > &td, int ind, char side) {

	for (int i = 0; i < td.size(); ++i) {
		if (td[i].first == s[ind]) {
			if (td[i].second == 'L') {
				ind--;
			}
			else {
				ind++;
			}
		}

		if (ind < 0 || ind > s.size() - 1) {
			break;
		}
	}

	int n = s.size();

	if ((side == 'L' && ind < 0) || (side == 'R' && ind >= n)) {
		return 1;
	}
	else {
		return 0;
	}

}

int clf(string s, vector<pair<char,char> > &td) {
	int l = 0;
	int r = s.size() - 1;

	if (!fall(s, td, l, 'L')) {
		return 0;
	}

	if (fall(s, td, r, 'L')) {
		return s.size();
	}

	while (l + 1 < r) {
		int k = (l + r) / 2;

		if (fall(s, td, k, 'L')) {
			l = k;
		}
		else {
			r = k;
		}
	}

	return l + 1;
}

int clr(string s, vector<pair<char,char> > &td) {
	int l = 0;
	int r = s.size() - 1;

	if (fall(s, td, l, 'R')) {
		return s.size();
	}

	if (!fall(s, td, r, 'R')) {
		return 0;
	}

	while (l + 1 < r) {
		int k = (l + r) / 2;

		if (!fall(s, td, k, 'R')) {
			l = k;
		}
		else {
			r = k;
		}
	}

	return s.size() - r;
}

int main() {
	int n, q;
	string s;

	cin >> n >> q >> s;
	vector<pair<char,char> > td(q);

	for (int i = 0; i < q; ++i) {
		cin >> td[i].first >> td[i].second;
	}

	int left = clf(s, td);
	int right = clr(s, td);

	cout << n - (left + right) << endl;
	
	return 0;
}