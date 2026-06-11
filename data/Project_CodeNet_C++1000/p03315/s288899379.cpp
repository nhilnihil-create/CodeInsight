#include<string>
#include<iostream>
using namespace std;


int main() {

	string s;

	cin >> s;

	int sum = 0;

	for (int i = 0; i < 4; i++) {
		if (s[i] == '+') {
			sum++;
		}
		else {
			sum--;
		}

		
	}
	cout << sum << endl;

	return 0;
}