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
#include<math.h>
#define int long long
using namespace std;
const int INF = 10000000000000;//5000000000000000

signed main() {
	string S;
	cin >> S;
	int one = 0;
	int zero = 0;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == '0') zero++;
		else one++;
	}
	cout << min(one, zero) * 2 << endl;
}