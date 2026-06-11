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
int Max(int(a), int(b), int(c)) {
	return max(max(a,b), c);
}
int Min(int(a), int(b), int(c)) {
	return min(min(a, b), c);
}





int main() {
	
	int N;
	cin >>N;
	vector<string> A(N);
	int a, b, c,s;
	a = 0;
	b = 0;
	c = 0;
	s = 0;

	rep(i, N) {
		cin >> A.at(i);
		rep(j, A.at(i).size() - 1) {
			if (A.at(i).at(j) == 'A' && A.at(i).at(j + 1) == 'B') {
				s++;
			}
		}
		if (A.at(i).at(0) == 'B' && A.at(i).at(A.at(i).size() - 1) == 'A') {
			a++;
		}
		else if (A.at(i).at(0) == 'B') {
			b++;
		}
		else if (A.at(i).at(A.at(i).size() - 1) == 'A') {
			c++;
		}
	}

	if (b+c == 0&&a!=0) {
		s +=(a - 1);
	}
	else {
		s += (a + min(b, c));
	}
	cout << s << endl;

}
