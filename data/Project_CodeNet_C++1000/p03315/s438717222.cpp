#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	string S;
	cin >> S;
	int plus = count(S.begin(), S.end(), '+');
	cout << plus - (4 - plus) << endl;

	return 0;
}

