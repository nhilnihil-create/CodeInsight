#include <iostream>
using namespace std;
int main() {
	char X,Y;
	cin >> X;
	cin >> Y;
	if (X > Y) {
		cout << ">";
		return 0;
	}
	if (X < Y) cout << "<";
	else cout << "=";

	return 0;
}