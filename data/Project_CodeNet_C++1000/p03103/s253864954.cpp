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
	ll N, M, an = 0;
	cin >> N >> M;
	vector<pair<ll, ll>> k(N);
	rep(i, N) {
		ll A, B;
		cin >> A >> B;
		k.at(i) = make_pair(A, B);
	}
	sort(k.begin(), k.end());
	ll i = 0;
	while (M > 0) {
		if (k.at(i).second > 0) {
			an += k.at(i).first;
			k.at(i).second--;
			M--;
		}
		else {
			i++;

		}
	}
	cout << an << endl;
}
