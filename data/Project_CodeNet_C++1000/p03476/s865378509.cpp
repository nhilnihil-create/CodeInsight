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
vector<ll> fact, factinv, inv;
ll mod = 1e9 + 7;
void prenCkModp(ll n) {
	fact.resize(n + 5);
	factinv.resize(n + 5);
	inv.resize(n + 5);
	fact.at(0) = fact.at(1) = 1;
	factinv.at(0) = factinv.at(1) = 1;
	inv.at(1) = 1;
	for (ll i = 2; i < n + 5; i++) {
		fact.at(i) = (fact.at(i - 1) * i) % mod;
		inv.at(i) = mod - (inv.at(mod % i) * (mod / i)) % mod;
		factinv.at(i) = (factinv.at(i - 1) * inv.at(i)) % mod;
	}

}
ll nCk(ll n, ll k) {
	return fact.at(n) * (factinv.at(k) * factinv.at(n - k) % mod) % mod;
}

bool p[100003];
ll c[100003];

int main() {
	rep(i, 100003)p[i] = true;
	p[0] = false;
	p[1] = false;
	for (ll i = 2; i * i <= 100002; i++) {
		if (p[i]) {
			for (ll j = 2*i; j <= 100002; j += i) {
				p[j] = false;
			}
		}
	}
	c[0] = 0;
	c[1] = 0;
	c[2] = 0;
	for (ll i = 3; i < 100003; i++) {
		if (i % 2 == 0) {
			c[i] = c[i - 1];
			continue;
		}
		if (p[i] && p[(i + 1) / 2]) {
			c[i] = c[i - 1] + 1;
		}
		else {
			c[i] = c[i - 1];
		}
	}
	ll Q;
	cin >> Q;
	vector<ll> L(Q);
	vector<ll> R(Q);
	rep(i, Q) {
		cin >> L[i] >> R[i];
	}
	rep(i, Q) {
		cout << c[R[i]] - c[L[i] - 1] << endl;
	}

}
