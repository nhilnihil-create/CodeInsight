#include <iostream>
using namespace std;

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (a + b == c + d)
		cout << "Balanced" << endl;
	else
		cout << (a + b < c + d ? "Right" : "Left") << endl;
	return 0;
}