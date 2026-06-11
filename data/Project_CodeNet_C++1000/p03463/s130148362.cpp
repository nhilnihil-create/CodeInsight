#include<iostream>
using namespace std;

int main() {
	int n, a, b;
	cin >> n >> a >> b;
	if (n == 2) {
		cout << "Borys" << endl;
	}
	else if ((b - a - 1) % 2 == 1) {
		cout << "Alice" << endl;
	}
	else {
		cout << "Borys" << endl;
	}
}