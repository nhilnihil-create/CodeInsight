#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int main() {
	int n, a, b;
	cin >> n >> a >> b;
	if (n * a >= b)
		cout << b << "\n";
	else
		cout << n * a << "\n";
}