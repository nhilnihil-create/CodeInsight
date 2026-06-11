#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	for (char c : s) {
		if (c == '1') cout << '9';
		else cout << '1';
	}
	return 0;
}