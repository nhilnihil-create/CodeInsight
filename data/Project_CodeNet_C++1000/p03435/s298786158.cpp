#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
	vector<int>a(3), b(3), c(3);
	bool ans = false;
	rep(i, 3)cin >> a[i];
	rep(i, 3)cin >> b[i];
	rep(i, 3)cin >> c[i];
	int sum = accumulate(all(a), 0) + accumulate(all(b), 0) + accumulate(all(c), 0);
	if (sum == (a[0] + b[1] + c[2]) * 3)ans = true;
	if (ans) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}
