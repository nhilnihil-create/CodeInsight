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
	string s; cin >> s;
	int year, month, day;
	sscanf(s.c_str(), "%d/%d/%d", &year, &month, &day);
	if (year <= 2019 && month <= 4 && day <= 30) {
		cout << "Heisei" << endl;
		return;
	}
	cout << "TBD" << endl;
	return;
}
int main() {
	solve();
	return 0;
}