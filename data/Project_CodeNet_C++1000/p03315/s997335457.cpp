#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>

using namespace std;

int main() {
	string S;
	cin >> S;
	int num = 0;
	for (auto s : S) {
		if (s == '+') num++;
		else if (s == '-') num--;
	}
	cout << num << endl;
	return 0;
}