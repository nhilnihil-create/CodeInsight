#include <iostream>

using namespace std;

int main() {
	string S;
	cin >> S;

	int topping_count = 0;
	for (int i = 0; i < S.length(); i++) {
		if (S.at(i) == 'o') {
			topping_count++;
		}
	}

	cout << 700 + 100 * topping_count << endl;

}