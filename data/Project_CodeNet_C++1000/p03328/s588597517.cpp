#include <iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	int n = (b - a) * (b - a + 1) / 2;
	cout << n - b << endl;
}
