#include <iostream>
#include <string>

using namespace std;


int main () {
	string str;
	cin >> str;

	int counter;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'o') {
			counter++;
		}
	}

	cout << 700 + 100 * counter << endl;

	return 0;
}