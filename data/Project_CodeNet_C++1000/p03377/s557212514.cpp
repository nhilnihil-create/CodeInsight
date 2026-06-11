#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int main() {
	int a, b, x;
	cin >> a >> b >> x;
	if (x >= a && x < a + b)
		cout << "YES" << "\n";
	else
		cout << "NO" << "\n";
}