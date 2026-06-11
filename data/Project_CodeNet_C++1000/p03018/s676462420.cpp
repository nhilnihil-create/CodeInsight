#include<iostream>
#include<string>
using namespace std;
int main() {
	//A
	/*
	int n;
	int a, b, c, d;
	cin >> n;
	cin >> a;
	cin >> b;
	cin >> c;
	cin >> d;
	string s;
	cin >> s;
	int i;
	for (i = a - 1; i <= c - 1; i++) {
		if ((s[i] == '#') && (s[i + 1] == '#')) {
			cout << "No";
			return 0;
		}
	}
	for (i = b - 1; i <= d - 1; i++) {
		if ((s[i] == '#') && (s[i + 1] == '#')) {
			cout << "No";
			return 0;
		}
	}
	if (c < d) {
		cout << "Yes";
		return 0;
	}
	else {
		for (i = b - 1; i <= d - 1; i++) {
			if ((s[i - 1] == '.') && (s[i + 1] == '.') && (s[i] == '.')) {
				cout << "Yes";
				return 0;
			}
		}
		cout << "No";
		return 0;
	}
	return 0;*/
	//B

	string s;
	long long int counter = 0;
	long long int counterA = 0;
	int bflag = 0;
	int i;
	cin >> s;
	for (i = 0; i < s.length(); i++) {
		if (s[i] == 'A') {
			if (bflag == 1) {
				bflag = 0;
				counterA = 0;
			}
			counterA++;
			//cout << counter;
		}
		else if (s[i] == 'B') {
			if (bflag == 1) {
				counterA = 0;
			}
			bflag = 1;
			//cout << counter;
		}
		else if (s[i] == 'C') {
			if (bflag == 1) {
				counter = counter + counterA;
				bflag = 0;
			}
			else {
				counterA = 0;
			}
			//cout << counter;
		}
	}
	cout << counter;
	return 0;
}