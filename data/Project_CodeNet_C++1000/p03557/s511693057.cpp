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


ll a[100009];


int main() {
	ll N, an = 0;
	cin >> N;
	vector<ll> A(N);
	vector<ll> B(N);
	vector<ll> C(N);
	rep(i, N) {
		cin >> A.at(i);
	}
	rep(i, N) {
		cin >> B.at(i);
	}
	rep(i, N) {
		cin >> C.at(i);
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	sort(C.begin(), C.end());
	ll a = 0, c = 0;
	rep(i, N) {
		while (a<N&&A.at(a) < B.at(i)) {
			a++;
		}
		while (c < N && C.at(c) <= B.at(i)) {
			c++;
		}
		an += (a * (N - c));
	}
	cout << an << endl;
}