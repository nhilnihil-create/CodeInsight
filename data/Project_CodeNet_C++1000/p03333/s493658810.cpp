#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, l[N], r[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> l[i] >> r[i];
	}
	sort(l + 1, l + n + 1);
	sort(r + 1, r + n + 1);
	reverse(l + 1, l + n + 1);
	long long tp = 0, fp = 0;
	for(int i = 1; i <= n; ++i) {
		tp += 2 * l[i];
		tp -= 2 * r[i];
		//
		if(r[i] > 0) {
			fp = max(fp, tp + 2 * r[i]);
		} else {
			fp = max(fp, tp);
		}
		//
		if(l[i] < 0) {
			fp = max(fp, tp - 2 * l[i]);
		} else {
			fp = max(fp, tp);
		}
	}
	cout << fp << endl;
	return 0;
}
