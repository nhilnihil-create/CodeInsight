#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

signed main() {
	string s; cin >> s;
	if(s[0] == s[1] && s[1] == s[2]) {
		cout << "Yes" << endl;
		return 0;
	}
	if(s[1] == s[2] && s[2] == s[3]) {
		cout << "Yes" << endl;
		return 0;
	}
	cout << "No" << endl;
}
