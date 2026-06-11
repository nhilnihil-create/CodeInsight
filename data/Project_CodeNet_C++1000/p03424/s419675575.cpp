#include "bits/stdc++.h"
using namespace std;

int main() {
	string mem;
	int n;
	int chk = 0;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> mem;
		if (mem == "Y")
			chk = 1;
	}
	if (chk) cout << "Four" << endl;
	else cout << "Three" << endl;
}