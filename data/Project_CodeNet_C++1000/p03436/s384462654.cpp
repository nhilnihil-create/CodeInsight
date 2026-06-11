#include <iostream>
#include <numeric>
#include <cmath>
#include <queue>
#include <limits>
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
ll Max(ll(a), ll(b), ll(c)) {
	return max(max(a, b), c);
}
ll Min(ll(a), ll(b), ll(c)) {
	return min(min(a, b), c);
}





int main() {

	ll R, C;
	cin >> R >> C ;
	ll cell[60][60];
	ll dx[4] = { -1,0,1,0 };
	ll dy[4] = { 0,1,0,-1 };
	ll w = 0;
	rep(i, 60) {
		rep(j, 60) {
			cell[i][j] = -2;
		}
	}

	rep(i, R) {
		string S;
		cin >> S;
		rep(j, C) {
			if (S.at(j) == '.') {
			cell[i][j] = -1;
			w++;
			}
		}
	}
	queue<pair<ll, ll>> q;
	cell[0][0] = 1;
	q.push(make_pair(0, 0));
	while (!q.empty()) {
		ll py = q.front().first;
		ll px = q.front().second;

		q.pop();
		rep(i, 4) {
			if (py + dy[i] < 0 || py + dy[i] >= R || px + dx[i] < 0 || px + dx[i] >= C)continue;
			if (cell[py + dy[i]][px + dx[i]] != -1)continue;

			cell[py + dy[i]][px + dx[i]] = cell[py][px] + 1;
			q.push(make_pair(py + dy[i], px + dx[i]));
		}
	}
	if (cell[R-1][C-1] == -1)cout << -1 << endl;
	else {
		cout << w-cell[R-1][C-1] << endl;
	}
	
}
