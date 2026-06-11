#include <iostream>
using namespace std;

int main() {
	string Ans[6] = { "abc","acb","bac","bca","cab","cba" };
	string S;
	cin >> S;
	for (int i = 0; i < 6; i++) if (S == Ans[i]) {
		cout << "Yes" << endl;
		return 0;
	}
	cout << "No" << endl;
}