#include <bits/stdc++.h>
typedef long long ll; 
 
using namespace std;

int main() {
	string s;
	cin >> s;

	int len = s.size();
	int res = len;
	for (int i = 0; i < len - 1; i++) {
		if (s[i] == s[i + 1]) continue;

		res = min(res, max(i + 1, len - i - 1));
	}

	cout << res << endl;
	return 0;
}
