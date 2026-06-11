#include <iostream>
using namespace std;
int a, b;
int main() {
	cin >> a >> b;
	cout << (a % 2 == 0 || b % 2 == 0 ? "Even" : "Odd") << endl;
	return 0;
}
