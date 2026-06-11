#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	cin >> s;
	int ans = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'o') {
			ans++;
		}
	}

	if (15 - s.length() + ans >= 8) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	return 0;
}