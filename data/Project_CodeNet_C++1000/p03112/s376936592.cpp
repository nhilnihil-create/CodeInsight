#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;


int main() {
	int a, b, q;
	cin >> a >> b >> q;
	set<long long int> sa, sb;
	unordered_map<long long int, int> uma, umb;
	for (int i = 0; i < a; i++) {
		long long int aa;
		cin >> aa;
		sa.insert(aa);
		uma[aa] = i;
	}	
	for (int i = 0; i < b; i++) {
		long long int bb;
		cin >> bb;
		sb.insert(bb);
		umb[bb] = i;
	}
	vector<long long int> va(a, -1), vb(b, -1);
	for (auto p : uma) {
		long long int d = p.first;
		int index = p.second;

		auto it = sb.lower_bound(d);
		if (it != sb.end()) {
			long long int diff = *it - d;
			if (va[index] == -1 || va[index] > diff) va[index] = diff;
		}
		if (it != sb.begin()) {
			it--;
			long long int diff = d - *it;
			if (va[index] == -1 || va[index] > diff) va[index] = diff;
		}
	}

	for (auto p : umb) {
		long long int d = p.first;
		int index = p.second;

		auto it = sa.lower_bound(d);
		if (it != sa.end()) {
			long long int diff = *it - d;
			if (vb[index] == -1 || vb[index] > diff) vb[index] = diff;
		}
		if (it != sa.begin()) {
			it--;
			long long int diff = d - *it;
			if (vb[index] == -1 || vb[index] > diff) vb[index] = diff;
		}
	}

	for (int i = 0; i < q; i++) {
		long long int x;
		cin >> x;
		long long int res = -1;
		auto it = sa.lower_bound(x);
		long long int temp = 0;
		if (it != sa.end()) {
			temp = abs(x - *it) + va[uma[*it]];
			if (res == -1 || temp < res) res = temp;
		}
		if (it != sa.begin()) {
			it--;
			temp = abs(x - *it) + va[uma[*it]];
			if (res == -1 || temp < res) res = temp;
		}

		it = sb.lower_bound(x);
		if (it != sb.end()) {
			temp = abs(x - *it) + vb[umb[*it]];
			if (res == -1 || temp < res) res = temp;
		}
		if (it != sb.begin()) {
			it--;
			temp = abs(x - *it) + vb[umb[*it]];
			if (res == -1 || temp < res) res = temp;
		}
		cout << res << endl;
	}
}
