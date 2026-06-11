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
	vector<ll> A(N+2);
	A.at(0) = 0;
	A.at(N + 1) = 0;
	ll S=0;
	rep(i, N) {
		cin >> A.at(i+1);
		S += abs(A.at(i + 1) - A.at(i));
	}
	S+= abs(A.at(N + 1) - A.at(N));
	rep(i, N) {
		cout << S + abs(A.at(i + 2) - A.at(i)) - abs(A.at(i + 1) - A.at(i)) - abs(A.at(i + 2) - A.at(i + 1)) << endl;
	}
}