#include <iostream>
#include <string>
using namespace std;

int main() {
	int d;
	cin >> d;
	string ans = "Christmas";
	int n = 25 - d;
	for (int i = 0; i < n; i++) {
		ans += " Eve";
	}
	cout << ans << endl;
	return 0;
}