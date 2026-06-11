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
	int smallCnt = 0;
	bool ok1 = s[0] =='A';
	bool ok2 = false, ok3 = false;
	rep(i, n) {
		if (i >= 2 && i <= n-2 && s[i] == 'C') ok2 = true;
		if (islower(s[i])) smallCnt++;
	}
	if (smallCnt == n-2) ok3 = true;
	if (ok1 && ok2 && ok3) cout << "AC" << endl;
	else cout << "WA" << endl;
	return 0;
}