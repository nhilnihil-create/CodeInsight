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
	int N; cin >> N;
	int num1, num2;
	int t_num = (N /10) / 10;
	for (int i = 0; i < 3; ++i) {
		num1 = (num1) * 10 + t_num;
	}
	t_num++;
	for (int i = 0; i < 3; ++i) {
		num2 = (num2) * 10 + t_num;
	}
	if (N <= num1) {
		cout << num1 << endl;
	} else {
		cout << num2 << endl;
	}
	return;
}
int main() {
	solve();
	return 0;
}