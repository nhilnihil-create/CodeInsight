#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
signed main() {
	int a[500], l = 2;
	for (int i = 2;; i++) {
		a[i] = i * (i - 1) / 2;
		if (a[i] > 100000)break;
		l++;
	}
	int n; cin >> n;
	int flag = 0;
	for (int i = 2; i < l; i++) {
		if (a[i] == n) { flag = i; break; }
		else if (a[i] > n)break;
	}
	if (!flag) { cout << "No\n"; return 0; }
	else {
		cout << "Yes\n";
		cout << flag << endl;
		int cnt1 = 0, cnt2 = 0, p1[500];
		for (int i = 0; i < flag; i++) {
			cout << flag - 1;
			for (int j = 0; j < cnt1; j++) {
				cout << ' ' << p1[j] - (flag - i) + 1;
			}
			for (int j = cnt1; j < flag - 1; j++) {
				cout << ' ' << ++cnt2;
			}
			p1[i] = cnt2;
			cnt1++;
			cout << endl;
		}
	}
}