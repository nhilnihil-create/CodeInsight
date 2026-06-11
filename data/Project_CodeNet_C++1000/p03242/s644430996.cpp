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
	if (s[0] == '1') s[0] = '9';
	else if (s[0] == '9') s[0] = '1';
	if (s[1] == '1') s[1] = '9';
	else if (s[1] == '9') s[1] = '1';
	if (s[2] == '1') s[2] = '9';
	else if (s[2] == '9') s[2] = '1';
	cout << s << endl;
	return;
}
int main() {
	solve();
	return 0;
}