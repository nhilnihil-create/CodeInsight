#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int main() {
	string s;
	cin >> s;
	int x = 0;
	for (int i = 0; i < 3; i++) {
		if (s[i] == 'o')
			x += 1;
	}
	cout << 700 + x * 100 << "\n";
}