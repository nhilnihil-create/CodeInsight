#include<iostream>
#include<string>
using namespace std;

int main() {
	int n;
	cin >> n;

	string S = to_string(n);

	for (int i = 0; i < 3; i++) {
		if (S[i] == '1') {
			cout << 9;
		}
		else if (S[i] == '9') {
			cout << 1;
		}
	}
}
