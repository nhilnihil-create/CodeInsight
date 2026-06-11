#include <iostream>
using namespace std;

int main() {
	string S;
	int n;
	cin >> S >> n;
	for (int i = 0; i < S.length(); i += n) cout << S[i];
	cout << endl;
}