#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int main() {
	int s;
	cin >> s;
	cout << s / 100 + (s / 10 - (s / 100) * 10) + s % 10 << "\n";
}