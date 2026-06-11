#include <bits/stdc++.h>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	
	
	string s;
	cin >> s;

	int c = 0;
	if (s[0] == 'o')c++;
	if (s[1] == 'o')c++;
	if (s[2] == 'o')c++;

	cout << 700 + (c * 100) << "\n";

	return 0;
}