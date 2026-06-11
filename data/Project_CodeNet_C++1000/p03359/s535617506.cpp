#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
using namespace std;
int main() {
	int a, b;
	cin >> a >> b;
	if (a > b)
		cout << a - 1 << "\n";
	else
		cout << a << "\n";
}