#include <bits/stdc++.h> 
const long long MOD = 1e9+7;
using namespace std;


int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);

	char b;
	cin >> b;

	if (b=='A') {
		cout << 'T' << endl;
	} else if (b=='C') {
		cout << 'G' << endl;
	} else if (b=='G') {
		cout << 'C' << endl;
	} else  if (b=='T') {
		cout << 'A' << endl;
	}
	return 0;
}
