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
	int N, M; cin >> N >> M;
	int ans = 1;
	for (int i = 1; i * i <= M; ++i) {
		int A = i;
		int B = M / A;
		if (M % A != 0) continue;
		if ((long)A * N <= M) ans = max(ans, A);	
		if ((long)B * N <= M) ans = max(ans, B);	
	}
	cout << ans << endl;
	return;
}
int main() {
	solve();
	return 0;
}