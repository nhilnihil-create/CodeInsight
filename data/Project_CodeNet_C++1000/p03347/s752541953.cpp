#include <iostream>
using namespace std;

const int N = 200 * 1000 + 5;

int a[N];
int last[N];
int main() {
	int n;
	bool b = false;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i > 0 && a[i] > a[i - 1] + 1) {
			b = true;
		}
	}
	if (b || a[0] > 0) {
		cout << -1;
		return 0;
	}
	long long ans = 0;
	int x = 0;
	for (int i = 0; i < n; i++) {
		bool b = false;
		if (a[i] == 0) {
			x = i;
			b = true;
		}
		else if (a[i] == a[i - 1] + 1) {
			x = i;
			ans++;
			b = true;
		}
		if (!b)
			ans += a[i];
		//cout << i << " " << x << endl;
	}
	cout << ans << endl;
	return 0;
}
