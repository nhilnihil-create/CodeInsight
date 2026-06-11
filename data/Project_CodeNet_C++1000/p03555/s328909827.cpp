#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int main() {
	string c1, c2;
	cin >> c1 >> c2;
	if (c1[0] == c2[2] && c1[2] == c2[0] && c1[1] == c2[1])
		cout << "YES" << "\n";
	else
		cout << "NO" << "\n";
}