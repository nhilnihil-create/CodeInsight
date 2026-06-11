#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	cin >> s;

	bool f = true;
	for (int i = 1; i < s.length(); i++) {
		if (s[i] != '9') {
			f = false;
		}
	}
	if (f) {
		cout << (long long)9 * (s.length() - 1) + s[0] - '0' << endl;
	}
	else {
		cout << (long long)9 * (s.length() - 1) + s[0] - '1' << endl;
	}

	return 0;
}