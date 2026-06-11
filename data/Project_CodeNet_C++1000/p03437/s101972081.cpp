#include <iostream>
using namespace std;

int main() {
	int X, Y;
	cin >> X >> Y;
	if (X % Y) cout << X;
	else cout << -1;
}