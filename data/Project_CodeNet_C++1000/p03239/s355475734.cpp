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
	int N, T;
	cin >> N >> T;
	int min_cost = 1010;
	rep(i, N) {
		int c, t;
		cin >> c >> t;
		if (t > T) continue;
		min_cost = min(c, min_cost);
	}
	if (min_cost==1010) cout << "TLE" << endl;
	else cout << min_cost << endl;
}