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
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;

	vector<int> t(n);
	t.at(0) = 0;
	for (int i=0; i<n-1; i++) {
		if (s.substr(i, 2)=="AC") t.at(i+1) = t.at(i) + 1;
		else t.at(i+1) = t.at(i);
	}

	rep(i, q) {
		int l, r;
		cin >> l >> r;
		cout << t.at(r-1) - t.at(l-1) << endl;
	}
}