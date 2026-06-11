#include <iostream>
#include <numeric>
#include <cmath>
#include <limits>
#include <stdio.h>
#include <iomanip>
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
	
	ll N;
	cin >> N;
	if (N == 0) {
		cout << 0 << endl; return 0;
	}
	vector<bool> AN;
	ll k = 1;
	while (N != 0) {
		if (N % (2*k) != 0) {
			AN.push_back(true);
			N -= k;
		}
		else {
			AN.push_back(false);
		}
		k *= -2;
	}
	rep(i, AN.size()) {
		cout << AN.at(AN.size() - i - 1);
	}
}