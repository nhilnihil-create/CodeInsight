#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <utility>
#include <stdio.h>
typedef long long ll;
const int INF = 1e9+1;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
using namespace std;

int main() {
	int n, m;
	int left, right;
	cin >> n >> m;
	left = 0;
	right = n;
	vector<int> l(m), r(m);
	for (int i = 0; i < m; i++)cin >> l.at(i) >> r.at(i);

	for (int i = 0; i < m; i++) {
		if (l.at(i) >= left && r.at(i) <= right) { left = l.at(i); right = r.at(i); }
		else if (l.at(i) <= left && r.at(i) <= right && r.at(i) >= left) { left = left; right = r.at(i); }
		else if (l.at(i) >= left && r.at(i) >= right&&l.at(i)<=right) { left = l.at(i); right = right; }
		else if (l.at(i) <= left && r.at(i) >= right) { left = left; right = right; }
		else { cout << 0 << endl; return 0; }
	}
	cout << right - left +1<< endl;
	return 0;
}