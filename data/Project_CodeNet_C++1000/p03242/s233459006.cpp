#include <iostream>
using namespace std;
int main() {
	string n;
	cin >> n;
	for (char c : n) cout << (c == '1' ? '9' : '1');
	cout << endl;
}