#include <iostream>
using namespace std;

int main() {
	char x, y;
	cin >> x >> y;
	char ans;
	if (x - y == 0) {
		ans = '=';
	} else if (x - y > 0) {
		ans = '>';
	} else {
		ans ='<';
	}
	cout << ans << endl;
	return 0;
}