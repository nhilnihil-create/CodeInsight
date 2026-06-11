
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
ll gcd(ll(a), ll(b)) {
	ll c = a;
	while (a % b != 0) {
		c = a % b;
		a = b;
		b = c;
	}
	return b;
}



int main() {

	ll A, B, C, X,an=0;
	cin >> A >> B >> C >> X;
	rep(a, A+1) {
		rep(b, B + 1) {
			rep(c, C + 1) {
				if (a * 500 + b * 100 + c * 50 == X) {
					an++;
				}
			}
		}
	}
	cout << an << endl;
}
