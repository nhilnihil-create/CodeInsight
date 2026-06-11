#include<iostream>
#include<string>
using namespace std;

int main(void) {
	string S;
	cin >> S;
	int Ans = 700;
	for (int i = 0; i < 3; i++) {
		if (S[i] == 'o') {
			Ans += 100;
		}
		else if (S[i] == 'o') {
			Ans += 100;
		}
		else if (S[i] == 'o') {
			Ans += 100;
		}
	}
	cout << Ans << endl;
}