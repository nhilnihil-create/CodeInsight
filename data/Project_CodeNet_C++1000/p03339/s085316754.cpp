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






int main() {
	int N;
	string S,B;
	cin >> N >> S;
	vector<int> vec(N);
	if (S.at(0) == 'E') {
		vec.at(0) = 0;
	}
	else {
		vec.at(0) = 1;
	}
	for (int i = 1; i < N; i++) {
		if (S.at(i) == 'E') {
			vec.at(i) = vec.at(i - 1);
		}
		else {
			vec.at(i) = vec.at(i - 1)+1;
		}
	}
	int m = 500000;
	for (int i = 1; i < N-1; i++) {
		m = min(m, vec.at(i - 1) +(N-1-i)-( vec.at(N-1) - vec.at(i )));
	}
	m = min(m, min(vec.at(N - 2),(N-1)- (vec.at(N-1) - vec.at(0))));
		cout << m << endl;
}