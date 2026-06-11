#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <iostream> // cout, endl, cin
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
#include <math.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<long long> A(N);
	vector<long long> B(N);
	vector<long long> C(N);

	for (int i = 0; i < N; i++) {
		cin >> A.at(i);
	}
	sort(A.begin(), A.end());
	
	for (int i = 0; i < N; i++) {
		cin >> B.at(i);
	}
	sort(B.begin(), B.end());
	
	for (int i = 0; i < N; i++) {
		cin >> C.at(i);
	}
	sort(C.begin(), C.end());

	long long ans = 0;
	for (int i = 0; i < N; i++) {
		long long numA, numC;
		auto IterA = lower_bound(A.begin(), A.end(), B.at(i));
		auto IterC = upper_bound(C.begin(), C.end(), B.at(i));
		numA = IterA - A.begin();
		numC = IterC - C.begin();
		ans += numA * (N - numC);
	}
	cout << ans << endl;
}