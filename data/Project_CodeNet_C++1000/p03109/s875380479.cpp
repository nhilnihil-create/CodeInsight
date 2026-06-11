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
	string s_year = s.substr(0, 4);
	string s_month = s.substr(5, 2);
	string s_day = s.substr(8, 2);
	int a = atoi(s_year.c_str());
	int b = atoi(s_month.c_str());
	int c = atoi(s_day.c_str());
	if (a <= 2019 && b <= 4 && c <= 30) {
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