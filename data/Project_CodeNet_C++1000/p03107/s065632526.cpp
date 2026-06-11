#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
 
int main() {
	string s;
	cin >> s;
	int c0 = 0, c1 = 0;
	rep(i, s.size()) {
		if (s[i] == '0') c0++;
		else c1++;
	}
	cout << 2 * min(c0,c1) << endl;  
	return 0;
}