#include <bits/stdc++.h>
using namespace std;

int main()
{
	char b;
	cin >> b;

	if ('A' == b) {
		cout << 'T' <<endl;
		return 0;
	}

	if ('T' == b) {
		cout << 'A' <<endl;
		return 0;
	}

	if ('C' == b) {
		cout << 'G' <<endl;
		return 0;
	}

	if ('G' == b) {
		cout << 'C' <<endl;
		return 0;
	}

	return 0;
}
