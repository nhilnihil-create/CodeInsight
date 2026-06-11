#include <iostream> // cout, endl, cin
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
#define rep(i,n) for(int i=0;i<(int)n;i++)
int main() {
	int64_t n, m; cin >> n >> m;
	vector<pair<int64_t, int64_t>> E(n);

	rep(i, n) {
		cin >> E[i].first >> E[i].second;
	}

	sort(E.begin(), E.end());

	int64_t sum = 0;
	int64_t i = 0;

	while (m > 0) {
		if (E[i].second <= m) {
			m -= E[i].second;
			sum += E[i].first * E[i].second;
			i++;
		}
		else {
			sum += E[i].first * m;
			m = 0;
		}
	}

	cout << sum << endl;
}
