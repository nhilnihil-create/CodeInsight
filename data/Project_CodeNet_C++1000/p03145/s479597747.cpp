#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int AB, BC, CA;
	cin >> AB >> BC >> CA;
	cout << min({ AB * BC, BC * CA, CA * AB }) / 2 << endl;
}