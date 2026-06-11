#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <set>
using namespace std;

#define rep(i, n) for (int i=0; i<int(n); i++)


int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int> > vec(n);
	rep(i, n) {
		int k;
		cin >> k;
		rep(j, k) {
			int a;
			cin >> a;
			vec.at(i).push_back(a);
		}
	}
	vector<int> cnt(m);
	rep(i, n) {
		rep(j, vec[i].size()) {
			cnt[vec.at(i).at(j) - 1] += 1;
		}
	}
	int res = 0;
	rep(i, cnt.size()) {
		if (cnt.at(i) == n) res++;
	}
	cout << res << endl;
}