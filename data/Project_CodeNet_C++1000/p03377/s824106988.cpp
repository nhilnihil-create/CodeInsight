#include <iostream>
#include <string>
using namespace std;

int main() {
	int a, b, x;
	cin >> a >> b >> x;
	string ans;
	if (a <= x && x <= a + b) {
		ans = "YES";
	} else {
		ans = "NO";
	}
	cout << ans << endl;
	return 0;
}