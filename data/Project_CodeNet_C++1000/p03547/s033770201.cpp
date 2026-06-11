// ABCABC078A - 

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ull;
typedef long long int ll;

int main() {
	char X, Y;
	cin >> X >> Y;

	if (X > Y) {
		cout << ">" << endl;
	} else if (X < Y) {
		cout << "<" << endl;
	} else {
		cout << "=" << endl;
	}

	return 0;
}
