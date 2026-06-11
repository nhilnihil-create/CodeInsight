#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
using namespace std;
int main() {
	int a, b;
	cin >> a >> b;
	if (a * b % 2 == 0)
		cout << "Even" << "\n";
	else
		cout << "Odd" << "\n";
}