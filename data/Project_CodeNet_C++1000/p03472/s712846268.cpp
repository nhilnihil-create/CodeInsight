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
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
int Max(long long(a), long long(b), long long(c)) {
	return max(max(a,b), c);
}
int Min(long long(a), long long(b), long long(c)) {
	return min(min(a, b), c);
}





int main() {

	long long N, H, m;
	cin >> N >> H;
	vector<long long> A(N);
	vector<long long> B(N);
	m = 0;
	rep(i, N) {
		cin >> A.at(i) >> B.at(i);
		m = max(m, A.at(i));
	}
	
	sort(B.begin(), B.end());
	reverse(B.begin(), B.end());
	long long i = 0;
	while (H > 0 && i < N && B.at(i) > m) {
		H -= B.at(i);
		i++;
	}
	if (H > 0) {
		i += (1 + (H - 1) / m);
	}

	cout << i << endl;
}
