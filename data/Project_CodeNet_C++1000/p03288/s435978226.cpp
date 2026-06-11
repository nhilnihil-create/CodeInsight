
#include <iostream>
#include <string>

using namespace std;

int main(void) {

	int s;

	cin >> s;

	if (s < 1200) {
		cout << "ABC" << endl;
	}
	else if (1200 <= s && s < 2800) {
		cout << "ARC" << endl;
	}
	else {
		cout << "AGC" << endl;
	}

	return 0;
}