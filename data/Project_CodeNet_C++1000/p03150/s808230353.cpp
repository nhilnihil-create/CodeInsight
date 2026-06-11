#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
	string s;
	cin >> s;
	int l = (int)s.size();
	bool ok = false;
	for (int i = 0; i < l; i++) {
		for (int j = i; j < l; j++) {
			string t = s.substr(0, i);
			string u = s.substr(j, l - i);
			if (t + u == "keyence") ok = true;
		}
	}
	if (ok) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}