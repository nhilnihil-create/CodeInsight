#include <iostream>
using namespace std;

int a, b, c = 0;


int main() {
	cin >> a >> b >> c;
	if (a == b) {
		if (b == c) {
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
		}
	}

	else {
		cout << "No\n";
	}

	return 0;
}