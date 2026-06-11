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
	string S;
	cin >> N >> S;
	vector<ll> W(N+1);
	ll an = N+3;
	W.at(0) = 0;
	rep(i, N) {
		if (S.at(i) == '.') {
			W.at(i + 1) = W.at(i) + 1;
		}
		else {
			W.at(i + 1) = W.at(i);
		}
	}
	rep(i, N+1) {
		
		an = min(an, (i - W.at(i)) + (W.at(N) - W.at(i)));
	}
	cout << an << endl;
}
