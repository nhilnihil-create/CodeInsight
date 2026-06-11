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
#include <math.h>
#include <cstdlib>
#define rep(i,n) for(int i = 0;i<(n);i++);
using namespace std;
using ld = long double;
using ll = long long;
const ll INF = 100100100100100;


int main() {
	ll N, Q;//nagasa N situmonn Q
	cin >> N >> Q;
	string S;
	cin >> S;
	vector<vector<ll>> num(Q, vector<ll>(2));
	vector<ll> ans(N+1);
	ans[0] = 0;
	for (int i = 0; i < Q; i++) {
		cin >> num[i][0] >> num[i][1];
	}
	for (int i = 0; i < N; i++) {
		if (S[i] == 'A' && S[i + 1] == 'C') {
			ans[i + 1] = ans[i] + 1;
		}
		else ans[i + 1] = ans[i];
	}
	for (int i = 0; i < Q; i++) {
		cout << ans[num[i][1]-1] - ans[num[i][0]-1] << endl;
	}
}