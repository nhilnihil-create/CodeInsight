#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
using namespace std;
int main() {
	int n , a;
	cin >> n >> a;
	if (n % 500 - a <= 0)
		cout << "Yes" << "\n";
	else
		cout << "No" << "\n";
}