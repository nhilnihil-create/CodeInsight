#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
	char x, y;
	cin >> x >> y;
	if (x == 'A') {x = '1';}
	if (x == 'B') {x = '2';}
	if (x == 'C') {x = '3';}
	if (x == 'D') {x = '4';}
	if (x == 'E') {x = '5';}
	if (x == 'F') {x = '6';}	
	if (y == 'A') {y = '1';}
	if (y == 'B') {y = '2';}
	if (y == 'C') {y = '3';}
	if (y == 'D') {y = '4';}
	if (y == 'E') {y = '5';}
	if (y == 'F') {y = '6';}
	if ((int)x > (int)y) {
		cout << ">" << endl;
	}
	if ((int)x < (int)y) {
		cout << "<" << endl;
	}
	if ((int)x == (int)y) {
		cout << "=" << endl;
	}
}