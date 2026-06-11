#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int main() {
	int a, b;
	cin >> a >> b;
	if (b > 0) {
		if (a + b >= a * b)
			cout << a + b << "\n";
		else
			cout << a * b << "\n";
	}
	else {
		if (a - b >= a * b)
			cout << a - b << "\n";
		else
			cout << a * b << "\n";
	}
}