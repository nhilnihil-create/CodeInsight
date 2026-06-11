#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	string ans = "ABC";
	if (999 < n) {
		ans = "ABD";
	}
	cout << ans << endl;
	return 0;
}