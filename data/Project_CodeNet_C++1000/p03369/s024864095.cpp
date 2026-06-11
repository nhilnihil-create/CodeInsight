#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>

using namespace std;

int main() {
	string topping;
	cin >> topping;
	int price = 700;
	for (int i = 0; i < 3; i++) {
		if (topping[i] == 'o') price += 100;
	}
	cout << price << endl;
	return 0;
}