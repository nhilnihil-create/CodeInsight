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
	string S, T; cin >> S >> T;
	vector<int> s(26, -1), g(26, -1);
	for (int i = 0; i < S.size(); ++i) {
		int a = S[i] - 'a';
		int b = T[i] - 'a';
		if (s[a] != -1 || g[b] != -1) {
			if (s[a] != b || g[b] != a) {
				cout << "No" << endl;
				return;
			}
		}
		s[a] = b;
		g[b] = a;
	}
	cout << "Yes" << endl;
	return;
}
int main() {
	solve();
	return 0;
}