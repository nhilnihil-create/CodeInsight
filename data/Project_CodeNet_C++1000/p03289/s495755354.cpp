#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	
	string s; cin >> s;
	string ans = "AC";
	if (s[0] != 'A') ans = "WA";
	int cnt = 0;
	int index;
	for (int i = 2; i < s.size() - 1; i++) {
		if (s[i] == 'C') {
			cnt++;
			index = i;
		}
	}
	if (cnt != 1) ans = "WA";
	for (int i = 0; i < s.size(); i++) {
		if (i == 0 || i == index) continue;
		if (!islower(s[i])) ans = "WA";
	}
	cout << ans << endl;
	return 0;
}