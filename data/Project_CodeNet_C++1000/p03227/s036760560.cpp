#include<string>
#include<iostream>
using namespace std;
int main() {
	string S;
	cin >> S;
	if (S.size() == 2) {
		cout << S << endl;
	}
	else if (S.size() == 3) {
		cout << S[2] << S[1] << S[0] << endl;
	}
	system("pause");
	return 0;
}