#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	
	string s; cin >> s;
	int cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'x') cnt++;
	}
	if (8 <= cnt) cout << "NO" << endl;
	else cout << "YES" << endl;
	return 0;
}