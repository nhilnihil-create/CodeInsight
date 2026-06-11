#include <iostream>
#include <numeric>
#include <cmath>
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
vector<ll> D;
void pre() {
	queue<ll> q;
	q.push(0);
	
	while (q.front() < 3333333334) {
		ll s = q.front();
		D.push_back(s);
		q.pop();
		q.push(s * 10 + 3);
		q.push(s * 10 + 5);
		q.push(s * 10 + 7);
	}
	return;
}




int main() {
	pre();
	ll N;
cin >> N;
	ll i = 0,an=0;

	while (D.at(i) <= N) {
		ll k = D.at(i);
		bool ch[9];
		rep(i, 9) {
			ch[i] = false;
		}
		while (k > 0) {
			ch[k % 10] = true;
			k /= 10;
		}
		if (ch[3] && ch[5] && ch[7])an++;
		i++;
	}
	cout << an << endl;
	

}