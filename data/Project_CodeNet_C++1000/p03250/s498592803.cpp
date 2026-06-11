#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

int main() {
	int a[3];
	for (int i = 0; i < 3; i++) {
		cin >> a[i];
	}
	sort(a, a+3);
	ostringstream oss;
	oss << a[2] << a[1];
	string m = oss.str();
	int n = stod(m);
	int ans = a[0] + n;
	cout << ans << endl;
	return 0;
}