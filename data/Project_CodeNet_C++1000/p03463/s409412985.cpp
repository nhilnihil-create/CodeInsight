#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, a, b;
	cin >> n >> a >> b;

	if ((b - a) % 2 == 1 && n == 4) cout << "Draw" << endl;
	else if ((b - a) % 2 == 0) cout << "Alice" << endl;
	else cout << "Borys" << endl;

	return 0;
}