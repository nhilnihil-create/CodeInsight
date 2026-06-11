#include <bits/stdc++.h>
using namespace std;
const int N = 200 * 1000 + 10;
int n, q;
string s;
pair<char, int> rd[N];
bool isvalR(int plc) {
	for (int i = 0; i < q; i++) {
		if (rd[i].first == s[plc])
			plc += rd[i].second;
		if (plc >= n)
			return true;
		if (plc < 0)
			return false;
	}
	return false;
}
bool isvalL(int plc) {
	for (int i = 0; i < q; i++) {
		if (rd[i].first == s[plc]) 
			plc += rd[i].second;
		if (plc < 0)
			return true;
		if (plc >= n)
			return false;
	}
	return false;
}
int getBSL() {
	int up = n, dw = -1;
//	cout << "L = " << endl;
	while (up - dw > 1) {
		int md = (up + dw) / 2;
//		cout << "md = " << md << endl;
		if (isvalL(md)) {
			dw = md;
		}
		else {
			up = md;
		}
	}
	return dw;
}
int getBSR() {
	int up = n, dw = -1;	
//	cout << "r = " << endl;
	while (up - dw > 1) {
		int md = (up + dw) / 2;
//		cout << "md = " << md << endl;
		if (isvalR(md)) {
			up = md;
		}
		else {
			dw = md;
		}
	}
	return up;
}
int main() {;
	cin >> n >> q;
	cin >> s;
	for (int i = 0; i < q; i++) {
		char x, y;
		cin >> x >> y;
		if (y == 'L') {
			rd[i] = {x, -1};
		}
		if (y == 'R') {
			rd[i] = {x, 1};
		}
	}
//	cout << isvalR(6) << endl;
	int l = getBSL();
	int r = getBSR();
	cout << n - (l + 1 + (n - r)); 
	return 0;
}
