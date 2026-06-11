#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	int N;
	cin >> N;

	double yen = 0, btc = 0;

	for (int i = 0; i < N; i++) {
		double x;
		string u;
		cin >> x >> u;
		if (u == "JPY") yen += x;
		else btc += x;
	}

	double ans = yen + (btc * 380000.0);

	cout << fixed << setprecision(10) << ans << endl;
}