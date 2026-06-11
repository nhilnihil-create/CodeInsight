#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int main() {
	int n, a;
	cin >> n >> a;
	if (a >= n % 500)
		cout << "Yes" << "\n";
	else
		cout << "No" << "\n";
}