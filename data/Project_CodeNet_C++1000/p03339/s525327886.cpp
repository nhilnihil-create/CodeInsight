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
using namespace std;

#define rep(i, n) for (int i=0; i<int(n); i++)
using ll = long long;


int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;

	int sum_w[n+1], sum_e[n+1];
	fill(sum_w, sum_w+n+1, 0);
	fill(sum_e, sum_e+n+1, 0);
	for (int i = 1; i <= n; i++) {
		sum_w[i] = sum_w[i-1];
		if (s[i-1]=='W') sum_w[i]++;
		sum_e[i] = sum_e[i-1];
		if (s[n-i]=='E') sum_e[i]++;
	}
	int res = n;
	rep(i, n) {
		res = min(res, sum_w[i] + sum_e[n-i-1]);
	}
	cout << res << endl;
}