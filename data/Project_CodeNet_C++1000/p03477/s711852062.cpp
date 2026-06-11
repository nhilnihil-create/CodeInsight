#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (a + b == c + d)
		cout << "Balanced" << endl;
	else if (a + b < c + d)
		cout << "Right" << endl;
	else
		cout << "Left" << endl;
}