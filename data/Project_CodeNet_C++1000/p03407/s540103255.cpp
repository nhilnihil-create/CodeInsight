#include <iostream>
#include <string>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	string ans;
	if (c <= a + b) {
		ans = "Yes";
	} else {
		ans = "No";
	}
	cout << ans << endl;
	return 0;
}