#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
using namespace std;
int main() {
	string s;
	cin >> s;
	int cun = 0;
	int cum = 0;
	int cud = 0;
	for (int i = 0; i < 3; i++) {
		if (s[i] == 'a')
			cun++;
		else if (s[i] == 'b')
			cum++;
		else
			cud++;
	}
	if (cun == 1 && cum == 1 && cud == 1)
		cout << "Yes" << "\n";
	else
		cout << "No" << "\n";
}