#include <iostream>
#include <bitset>
#include <math.h>
using namespace std;

int main() {
	
	string str;
	cin >> str;
	int ans = 0;
	for (int i = 0;i < 8;i++) {
		bitset<3> b(i);

		ans = str[0] - '0';
		for (int j = 0;j < 3;j++) {
			if (b.test(j)) {
				ans += str[j+1] - '0';
			}
			else {
				ans -= str[j + 1] - '0';
			}
		}
		
		if (ans == 7) {
			cout << str[0];
			for (int j = 0;j < 3;j++) {
				if (b.test(j)) {
					cout << "+";
				}
				else {
					cout << "-";
				}
				cout << str[j + 1];
			}
			cout << "=7\n";
			return 0;
		}

	}

	return 0;
}