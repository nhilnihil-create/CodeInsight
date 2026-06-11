#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if (a + b >= c)
		cout << "Yes" << "\n";
	else
		cout << "No" << "\n";
}