#include <iostream>
using namespace std;

int main() {
	string S;
	cin >> S;
	int k = S.length();
	int win = 0;
	for (char c : S) win += (int)(c == 'o');
	cout << (15 - k + win >= 8 ? "YES" : "NO") << endl;
}