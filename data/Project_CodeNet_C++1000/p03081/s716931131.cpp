#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, q;
char t[N], d[N];
string s;

bool check(int x, int type) {
	char cur = s[x];
	for (int i = 0; i < q; ++i) {
		if (t[i] == cur) {
			x += (d[i] == 'L') ? -1 : +1;
			if (x >= 0 && x < n) cur = s[x];
		}
		if (x < 0 || x >= n) {
			if (type == 0 && x < 0) return true;
			if (type == 1 && x >= n) return true;
			return false;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	cin >> n >> q;
	cin >> s;
	for (int i = 0; i < q; ++i) {
		cin >> t[i] >> d[i];
	}
	
	int res = n;
	
	int low = 0, high = n - 1;
	while(low < high) {
		int mid = ((low + high + 1) >> 1);
		if (check(mid, 0)) low = mid;
		else high = mid - 1;
	}
	if (check(low, 0)) res -= low + 1;
	cerr << low << endl;
	
	low = 0, high = n - 1;
	while(low < high) {
		int mid = ((low + high) >> 1);
		if (check(mid, 1)) high = mid;
		else low = mid + 1;
	}
	if (check(low, 1)) res -= n - low;
	cerr << low << endl;
	
	cout << res << endl;
}
