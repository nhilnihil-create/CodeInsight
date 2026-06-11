#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <random>

using namespace std;


// range query using fenwick tree
// note index starts at 1

class fenwick_tree {
	vector<long long> t;
	long long size;
public:
	fenwick_tree(long long n) {
		t.assign(n + 1, 0);
		size = n + 1;
	}

	long LSOne(long long k) {	// least significant 1-bit
		return k & (-k);
	}

	void update(long long index, long long val) {	// can go up or go down
		for (; index < size; index += LSOne(index)) t[index] += val;
	}

	long long query_full(long long a, long long b) {		// range query
		return query(b) - ((a <= 1) ? 0 : query(a - 1));
	}

	long long query(long long b) {	// range query 1..b
		if (b < 1) return 0;

		long long sum = 0;
		for (; b; b -= LSOne(b)) sum += t[b];
		return sum;
	}
};



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long n, i, j, k, ans, aa, bb, cc, ss, x, goal;
	cin >> n;
	vector<long long> a(n), b(n), s(n + 1);
	for (i = 0; i < n; i++) cin >> a[i]; 

	goal = (n * (n + 1) / 2 + 1) / 2;

	aa = 1; bb = 1E9;
	while (aa < bb) {
		cc = (aa + bb + 1) / 2;

		// reprocess a->b, s
		s[0] = n + 1;
		for (i = 0; i < n; i++) {
			if (a[i] >= cc) b[i] = 1;
			else b[i] = -1;
			s[i + 1] = s[i] + b[i];
		}

		fenwick_tree ft(2 * n + 1);
		ss = 0;		// # of medians >= cc
		for (i = 0; i <= n; i++) {
			x = ft.query_full(1, s[i]);
			ss += x;
			ft.update(s[i], 1);
		}

		if (ss < goal) bb = cc - 1;
		else aa = cc;
	}

	cout << aa << "\n";


	return 0;
}
