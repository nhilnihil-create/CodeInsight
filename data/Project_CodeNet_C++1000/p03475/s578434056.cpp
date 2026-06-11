#include <iostream>
#include <numeric>
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
#define rep(i, n) for (int i = 0; i < (int)(n); i++)




int main() {

	int N;
	cin >> N;
	vector<int> C(N);
	vector<int> S(N);
	vector<int> F(N);
	for (int i = 0; i < N-1; i++) {
		cin >> C.at(i);
		cin >> S.at(i);
		cin >> F.at(i);
	}
	
	rep(i, N - 1) {
		int time = 0;
		for (int j = i; j < N-1; j++) {
			int check = S.at(j);
			while (time > check) {
				check += F.at(j);
			}
			time = check;
			time += C.at(j);
		}
		cout << time << endl;
	}
	cout << 0 << endl;
}