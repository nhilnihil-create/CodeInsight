#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	string s; cin >> s;
	int n = s.size();
	int tmp1 = 0;
	int tmp2 = 0;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			if (s[i] == '0') {}
			else tmp1++;
		}
		else {
			if (s[i] == '0') tmp1++;
			else {}
		}
		if (i % 2 == 0) {
			if (s[i] == '0') tmp2++;
			else {}
		}
		else {
			if (s[i] == '0') {}
			else tmp2++;
		}
	}
	cout << min(tmp1, tmp2) << endl;
	return 0;
}