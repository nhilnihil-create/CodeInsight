#include<iostream>

using namespace std;

int main() {
	string str;
	int count = 0;
	cin >> str;
	for (int i = 0; i < 3; i++) {
		if (str[i] == '1') {
			count++;
		}
	}
	printf("%d", count);

	return 0;
}