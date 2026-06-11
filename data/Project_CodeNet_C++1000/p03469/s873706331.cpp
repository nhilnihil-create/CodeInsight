#include <bits/stdc++.h>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	
	string s;
	cin >> s;

	if (s[3] == '7')s[3] = '8';

	cout << s << "\n";

	return 0;
}