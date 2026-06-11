#include <iostream>
using namespace std;
int main() {
	string S, T;
	cin >> S >> T;
	cout << (S[0] == T[2] && S[1] == T[1] && S[2] == T[0] ? "YES" : "NO") << endl;
}
