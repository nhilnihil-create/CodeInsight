#include <iostream>

using namespace std;

int main()
{
	string S;
	cin >> S;

	int win = 0;
	for (int i = 0; i < S.length(); i++) {
		if (S[i] == 'o') {
			win++;
		}
	}

	if (win + (15 - S.length()) > 7) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}


