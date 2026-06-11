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
using namespace std;

#define rep(i, n) for (int i=0; i<int(n); i++)
#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))
using ll = long long;


int main() {
	int n, k;
	cin >> n >> k;
	int X[100005];
	rep(i, n) cin >> X[i];

	int res = 1000000000;
	for (int i=0; i<=n-k; i++) {
		int l_x = X[i];
		int r_x = X[i+k-1];
		int time = min(abs(l_x) + abs(l_x-r_x), abs(r_x) + abs(l_x - r_x));
		res = min(res, time);
	}
	cout << res << endl;
}