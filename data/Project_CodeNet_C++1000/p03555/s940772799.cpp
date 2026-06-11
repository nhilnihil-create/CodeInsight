#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int main() {
	char c1, c2, c3, c4, c5, c6;
	cin >> c1 >> c2 >> c3 >> c4 >> c5 >> c6;
	if (c1 == c6 && c2 == c5 && c3 == c4)
		cout << "YES" << "\n";
	else
		cout << "NO" << "\n";
}