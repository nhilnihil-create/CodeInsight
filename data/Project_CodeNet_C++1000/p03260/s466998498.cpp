#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int a, b;
	cin >> a >> b;

	int c = 3;
	cout << (a*b*c % 2 == 1 ? "Yes" : "No") << endl;

	return 0;
}