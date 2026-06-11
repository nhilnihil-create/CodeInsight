#include <bits/stdc++.h>
using namespace std;

int main() {
	char x[2];
	int i[2];
	for (int j = 0; j < 2; j++)
	{
		char tmp;
		cin >> tmp;
		if (tmp == 'A') {
			i[j] = 10;
		}
		else if (tmp == 'B') {
			i[j] = 11;
		}
		else if (tmp == 'C') {
			i[j] = 12;
		}
		else if (tmp == 'D') {
			i[j] = 13;
		}
		else if (tmp == 'E') {
			i[j] = 14;

		}
		else if (tmp == 'F') {
			i[j] = 15;
		}
	}
	if (i[0] < i[1]) {
		cout << '<' << endl;
	}
	else if (i[0] == i[1]) {
		cout << '=' << endl;
	}
	else {
		cout << '>' << endl;
	}
	
}