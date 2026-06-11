#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
using namespace std;
int main() {
	int a, b;
	cin >> a >> b;
	if (a > 8 || b > 8)
		cout << ":(" << "\n";
	else
		cout << "Yay!" << "\n";
}