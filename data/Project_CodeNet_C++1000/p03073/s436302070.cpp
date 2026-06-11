#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 29;
 
int main() {
	string s;
	cin >> s;
	int n = s.size();
	string a = "", b = "";
	rep(i, n) {
		if (i % 2 == 0) {
			a += '0';
			b += '1';
		}
		else {
			a += '1';
			b += '0';
		}
	}
	int cntA = 0, cntB = 0;
	rep(i, n) {
		if (s[i] != a[i]) cntA++;
		if (s[i] != b[i]) cntB++;
	}
	cout << min(cntA, cntB) << endl;
	return 0;
}