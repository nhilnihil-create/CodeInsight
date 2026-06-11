#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if ((b - a <= d && b - a >= -d) && (c - b <= d && c - b >= -d))
		cout << "Yes" << "\n";
	else if (a - c <= d && a - c >= -d)
		cout << "Yes" << "\n";
	else
		cout << "No" << "\n";
}