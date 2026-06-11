#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
ll t[100005], x[100005], y[100005];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t[i] >> x[i] >> y[i];
	}
	int index;
	int sa;
	bool ok = true;
	if (n == 1) {
		index = t[0] - 0;
		sa = abs(x[0] - 0) + abs(y[0] - 0);
		if (index < sa || (index % 2 != sa % 2)) {
			ok = false;
		}
	}
	for (int i = 0; i < n - 1; i++) {
		index = t[i + 1] - t[i];
		sa = abs(x[i + 1] - x[i]) + abs(y[i + 1] - y[i]);
		if (index < sa || (index % 2 != sa % 2)) {
			ok = false;
		}
	}
	if (ok) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}

