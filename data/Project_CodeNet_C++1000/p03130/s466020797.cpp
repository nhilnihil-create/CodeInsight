#include <iostream>
#include <numeric>
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
	int A, B, C, D,E,F;
	string an = "NO";
	cin >> A >> B >> C >> D >> E >> F;
	vector<int> n(4);
	n.at(A-1)++;
	n.at(B - 1)++;
	n.at(C - 1)++;
	n.at(D - 1)++;
	n.at(E - 1)++;
	n.at(F - 1)++;

	if (Max(max(n.at(0), n.at(1)), n.at(2), n.at(3)) < 3) {
		an = "YES";
	}

	cout << an << endl;
	
}

