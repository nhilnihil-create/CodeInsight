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
	vector<pair<int64_t, int> > vec(n);
	rep(i, n) {
		int64_t a;
		int b;
		cin >> a >> b;
		vec.at(i) = make_pair(a, b);
	}
	sort(vec.begin(), vec.end());
	int64_t res = 0;
	rep(i, n) {
		int num = min(m, vec.at(i).second);
		res += vec.at(i).first * num;
		m -= num;
	}
	cout << res << endl;
}