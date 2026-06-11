#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	if (n == 1) {
		cout << "Hello World" << endl;
		return 0;
	} else if (n == 2) {
		int a, b;
		cin >> a >> b;
		int ans = a + b;
		cout << ans << endl;
		return 0;
	}
}