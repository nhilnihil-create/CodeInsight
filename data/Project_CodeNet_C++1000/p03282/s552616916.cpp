#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
 
int main() {
	string s;
	ll k;
	cin >> s >> k;
	int count1 = 0;
	char c;
	rep(i, s.size()) {
		if (s[i] == '1') count1++;
		else {
			c = s[i];
			break;
		}
	}
	if (count1 >= k) cout << 1 << endl;
	else cout << c << endl;
	return 0;
}