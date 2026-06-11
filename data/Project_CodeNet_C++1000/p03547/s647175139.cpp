#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int main() {
	char x, y;
	cin >> x >> y;
	if (x > y)
		cout << ">" << "\n";
	else if (x < y)
		cout << "<" << "\n";
	else
		cout << "=" << "\n";
}