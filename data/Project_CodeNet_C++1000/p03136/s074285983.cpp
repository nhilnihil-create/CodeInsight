#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long int64;
const double PI = 3.14159265358979323846;
const double EPS = 1e-12;
const int INF = 1<<29;
const long long  INFL = 1e18;
const int MOD = 1000000007;
const int MAX = 210000;
const int MAX_NUM = 999999999;
void solve() {
	int n; cin >> n;
	vector<int> l(n);
	for (int i = 0; i < l.size(); ++i) cin >> l[i];
	sort(all(l));
	int sum = 0;
	int max = l[l.size() - 1];
	for (int i = 0; i < l.size() - 1; ++i) sum += l[i];
	if (max < sum) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	return;
}
int main() {
	solve();
	return 0;
}