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
	vector<int> num(3);
	for (int i = 0; i < num.size(); ++i) cin >> num[i];
	sort(num.rbegin(), num.rend());
	cout << max((num[0] * 10 + num[1]) + num[2], num[0] + (num[1] * 10 + num[2])) << endl;
	return;
}
int main() {
	solve();
	return 0;
}