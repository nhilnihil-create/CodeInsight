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
#include <stack>
#include <deque>
#include <bitset>
using namespace std;

#define rep(i, n) for (int i=0; i<int(n); i++)
#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))
using ll = long long;


int main() {
	int n;
	cin >> n;
	vector<vector<int> > vec(n, vector<int>(10));
	vector<vector<int> > p(n, vector<int>(11));
	rep(i, n) {
		rep(j, 10) cin >> vec.at(i).at(j);
	}
	rep(i, n) {
		rep(j, 11) cin >> p.at(i).at(j);
	}
	int res = -(1<<30);
	for (int bit=1; bit<(1<<10); bit++){

		int total = 0;
		for (int shop=0; shop<n; shop++) {
			int cnt = 0;
			rep(i, 10) {
				if ((bit & (1<<i)) && vec.at(shop).at(i)==1) cnt++;
			}
			int sales = p.at(shop).at(cnt);
			total += sales;
		}
		res = max(res, total);
	}
	cout << res << endl;
}