#include <iostream>
#include <numeric>
#include <cmath>
#include <limits>
#include <stdio.h>
#include <iomanip>
#include <cstdlib>
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
using namespace std;
using ll = long long;
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
ll Max(ll(a), ll(b), ll(c)) {
	return max(max(a, b), c);
}
ll Min(ll(a), ll(b), ll(c)) {
	return min(min(a, b), c);
}





int main() {

	ll c[3][3];
	rep(i, 3) rep(j, 3) cin >> c[i][j];
	ll a[3];
	ll b[3];
	a[0] = 0;
	rep(i, 3) {
		b[i] = c[0][i];
	}
	a[1] = c[1][0] - b[0];
	a[2] = c[2][0] - b[0];
	rep(i, 2) rep(j, 2) {
		if (a[i + 1] + b[j + 1] != c[i + 1][j + 1]) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}