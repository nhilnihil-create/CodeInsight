#include <iostream>
using namespace std;

int main() {
	int count = 0;
	char s;

	for (int i = 0; i < 3; i++) {
		cin >> s;
		if (s == '1') {
			count++;
		}
	}
	cout << count << endl;
}