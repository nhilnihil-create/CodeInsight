#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	string s, t; cin >> s >> t;
	int p = s.size();
	bool can = false;
	string tmp = s;
	string y;
	string z;
	while (p--) {
		if (tmp == t) {
			can = true;
		}
		y = tmp.substr(0, tmp.size() - 1);
		z = tmp.back();
		tmp = "";
		tmp += z;
		tmp += y;
	}
	if (can) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}