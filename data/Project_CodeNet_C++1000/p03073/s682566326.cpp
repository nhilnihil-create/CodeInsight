#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;

	int n = s.size(), ans = 0;
	for (int i = 0; i < n-1; i++) {
		if (s[i] == s[i+1]) {
			if (s[i] == '0') s[i+1] = '1';
			else s[i+1] = '0';
			ans++;
		}
	}
	cout << ans << endl; 
}