#include <bits/stdc++.h>

using namespace std;

int main() {
	string n;
	cin >> n;
	for (int i = 0; i < n.length(); ++i)
		if (n[i] == '9') putchar('1');
		else if (n[i] == '1') putchar('9');
			else putchar(n[i]);
	return 0;
}