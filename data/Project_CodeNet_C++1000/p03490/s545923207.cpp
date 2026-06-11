#include <bits/stdc++.h>
using namespace std;

const int MAX = 8005;
int kx[MAX];
int ky[MAX];

int main() {
	// freopen("a.in", "r", stdin);
	string s; cin >> s;
	int x, y; cin >> x >> y;
	bool r = true; // right
	s += 'T';
	int n = s.length();
	bool seent = false;
	vector<int> dx, dy;
	int ct = 0;
	int fixedx = 0;
	for (int i=0; i<n; i++) {
		if (s[i] == 'T') { 
			if (!seent) { seent = true; fixedx = ct; ct = 0; r = !r; continue; }
			if (r) { dx.push_back(ct); }
			else { dy.push_back(ct); }
			ct = 0; r = !r;
		}
		else {
			ct++;
		}
	}
	int sumx = 0; for (int i : dx) { sumx += i; }
	int sumy = 0; for (int i : dy) { sumy += i; }
	kx[0] = true;
	for (int i : dx) {
		for (int j = MAX-1-i; ~j; j--) {
			if (kx[j]) { kx[j+i] = true; }
		}
	}
	ky[0] = true;
	for (int i : dy) {
		for (int j = MAX-1-i; ~j; j--) {
			if (ky[j]) { ky[j+i] = true; }
		}
	}
	kx[0] = true; ky[0] = true;
	bool okx = false, oky = false;
	for (int i=0; i<MAX; i++) {
		if (kx[i]) {
			int j = sumx - i;
			if (fixedx + i-j == x) { okx = true; }
		}
	}
	for (int i=0; i<MAX; i++) {
		if (ky[i]) {
			int j = sumy - i;
			if (i-j == y) { oky = true; }
		}
	}
	cout << ((okx && oky)?"Yes":"No") << endl;
}