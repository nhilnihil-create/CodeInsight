#include <iostream>
#include <vector>
using namespace std;

int main() {
	long long x, y;

	cin >> x >> y;
	int c = 0;
	while (x <= y) {
		x = 2 * x;
		c++;
	}

	cout << c << endl;

}