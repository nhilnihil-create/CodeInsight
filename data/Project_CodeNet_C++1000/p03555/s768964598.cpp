#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string s[2];
	cin >> s[0] >> s[1];
	reverse(s[1].begin(), s[1].end());

	if (s[0] == s[1]) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	return 0;
}