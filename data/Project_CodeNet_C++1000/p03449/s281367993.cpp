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

	ll N;
	cin >> N;
	vector<ll> ue(N);
	vector<ll> si(N);
	ll wa = 0;
	rep(i, N) {
		cin >> ue.at(i);

	}
	wa = 0;
	rep(i, N) {
		cin >> si.at(i);
	}

	ll an = 0;
	rep(i, N) {
		ll get = 0;
		for (ll j = 0; j <= i; j++) {
			get += ue.at(j);
		}
		for (ll j = i; j < N; j++) {
			get += si.at(j);
		}
		an = max(an, get);
	}
	cout << an << endl;
}
