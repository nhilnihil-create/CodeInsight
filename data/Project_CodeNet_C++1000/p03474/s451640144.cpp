#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 29;
 
int main() {
	int a, b;
	string s;
	cin >> a >> b >> s;
	bool ok = true;
	if (s[a] != '-') ok = false;
	rep(i, a+b+1) {
		if (i == a) continue;
		if (!isdigit(s[i]))  ok = false;
	} 
	if (ok) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}