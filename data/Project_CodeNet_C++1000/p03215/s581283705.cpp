#include <bit>
#include <bitset>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <queue>
#include <stack>


typedef long double ld;
typedef long long ll;

using namespace std;

#define MAXN (1 << 10)

ll a[MAXN], s[MAXN];
vector<ll> v;
int n, k;

void solve(vector<ll> & v, int pos, ll cur) {
	if (pos < 0) {
		cout << cur << endl;
		return;
	}
	vector<ll> tv;
	ll posmask = (1LL << pos);
	for (int i = 0; i < v.size(); i++) {
		if (v[i] & posmask) {
			tv.push_back(v[i]);
		}
	}
	if (tv.size() >= k) {
		solve(tv, pos - 1, cur | posmask);
	} else {
		solve(v, pos - 1, cur);
	}
}

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] += a[i] + s[i - 1];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			v.push_back(s[j] - s[i - 1]);
		}
	}
	solve(v, 41, 0);	
	return 0;
}
