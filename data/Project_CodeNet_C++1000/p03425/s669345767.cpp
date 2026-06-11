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
	long long N;
	cin >> N;
	vector<int> MARCH(5);
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		if (s.at(0) == 'M') MARCH.at(0)++;
		else if(s.at(0) == 'A') MARCH.at(1)++;
		else if (s.at(0) == 'R') MARCH.at(2)++;
		else if (s.at(0) == 'C') MARCH.at(3)++;
		else if (s.at(0) == 'H') MARCH.at(4)++;
	}

	long long ttl = 0;
	
	for (int i = 0; i < (1 << 5); i++) {
		long long ans = 1;
		bitset<5> X(i);
		int sum = 0;
		for (int j = 0; j < 5; j++) {
			if (X.test(j)) sum++;
		}
		if (sum == 3) {
			for (int k = 0; k < 5; k++) {
				if (X.test(k) == 0) continue;
				else if (X.test(k) == 1 && MARCH.at(k) != 0) ans *= X.test(k) * MARCH.at(k);
				else if (X.test(k) == 1 && MARCH.at(k) == 0) {
					ans = 0;
					break;
				}
			}
		}
		else continue;
		ttl += ans;
	}
	cout << ttl << endl;
}