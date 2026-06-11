#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
using namespace std;
int main() {
	string s;
	cin >> s;
	int sum = 700;
	if (s[0] == 'o')
		sum += 100;
	if (s[1] == 'o')
		sum += 100;
	if (s[2] == 'o')
		sum += 100;
	cout << sum << "\n";
}