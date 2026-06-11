#include <iostream>
using namespace std;

int main() {
	string S;
	cin >> S;
	if (S.length() == 2) cout << S << endl;
	else cout << S[2] << S[1] << S[0] << endl;
}