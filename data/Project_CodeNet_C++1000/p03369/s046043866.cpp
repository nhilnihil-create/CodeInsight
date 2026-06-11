#include <iostream>
using namespace std;
int main() {
	char s;
	int pri = 700;

	for (int i = 0; i < 3; i++) {
		cin >> s;
		if (s == 'o') {
			pri = pri + 100;
		}
	}
	cout << pri << endl;
}