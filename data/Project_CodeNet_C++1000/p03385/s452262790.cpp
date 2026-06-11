#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int main() {
	string s;
	cin >> s;
	int x = 0;
	int y = 0;
	int z = 0;
	for (int i = 0; i < 3; i++) {
		if (s[i] == 'a')
			x += 1;
		else if (s[i] == 'b')
			y += 1;
		else
			z += 1;
	}
	if (x == 1 && y == 1 && z == 1)
		cout << "Yes" << "\n";
	else
		cout << "No" << "\n";
}