#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int main() {
	int n;
	cin >> n;
	if ((n % 1000) % 111 == 0 || (n - n % 10) % 1110 == 0)
		cout << "Yes" << "\n";
	else
		cout << "No" << "\n";
}