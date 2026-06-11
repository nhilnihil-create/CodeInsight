#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
	int a, b;
	
	cin >> a;
	cin >> b;

	if (a*b % 2) {
		cout << "Odd" << endl;
	}
	else {
		cout << "Even" << endl;
	}

	return 0;
}