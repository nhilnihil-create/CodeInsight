#include <iostream>
using namespace std;

int main() {
	string S;
	cin >> S;
	int ans = 0;
	for (char c : S) ans += (c == '+' ? 1 : -1);
	cout << ans << endl;
}