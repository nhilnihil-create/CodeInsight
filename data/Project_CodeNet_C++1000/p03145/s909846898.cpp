#include<iostream>

using namespace std;

int main() {
	int AB, BC, CA;
	cin >> AB >> BC >> CA;

	if (CA * CA == AB * AB + BC * BC) {
		cout << AB * BC / 2 << endl;
	}
}
