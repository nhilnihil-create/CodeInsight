
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
int Max(int(a), int(b), int(c)) {
	return max(max(a, b), c);
}
int Min(int(a), int(b), int(c)) {
	return min(min(a, b), c);
}





int main() {
	ll N;
	vector<ll> n(5);
	cin >> N;
	rep(i, N) {
		string S;
		cin >> S;
		if (S.at(0) == 'M') {
			n.at(0)++;
		}
		if (S.at(0) == 'A') {
			n.at(1)++;
		}
		if (S.at(0) == 'R') {
			n.at(2)++;
		}
		if (S.at(0) == 'C') {
			n.at(3)++;
		}
		if (S.at(0) == 'H') {
			n.at(4)++;
		}
	}
	ll an = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = i + 1; j < 4; j++) {
			for (int k = j + 1; k < 5; k++) {
				an += n.at(i) * n.at(j) * n.at(k);
			}
		}
	}
	 cout<<an << endl;
}
