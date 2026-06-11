#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
typedef pair<int, P> E;
const LL MOD = 1000000007LL;
bool dpX[2][16001];
bool dpY[2][16001];
int main() {
	string s;
	cin >> s;
	int x, y;
	cin >> x >> y;
	int pos = 0;
	while (pos < s.size() && s[pos] == 'F') x--, pos++;
	vector<int> vx, vy;
	bool dir = 0;
	int d = 0;
	while (pos < s.size()) {
		if (s[pos] == 'T') {
			if (dir) vy.push_back(d);
			else vx.push_back(d);
			d = 0;
			dir ^= 1;
		}
		else {
			d++;
		}
		pos++;
	}
	if (dir) vy.push_back(d);
	else vx.push_back(d);
	dpX[0][8000] = 1;
	for (int i = 0; i < vx.size(); i++) {
		for (int j = 0; j <= 16000; j++) dpX[(i + 1) % 2][j] = 0;
		for (int j = 0; j <= 16000; j++) {
			if (j + vx[i] <= 16000) dpX[(i + 1) % 2][j + vx[i]] |= dpX[i % 2][j];
			if (j - vx[i] >= 0) dpX[(i + 1) % 2][j - vx[i]] |= dpX[i % 2][j];
		}
	}
	dpY[0][8000] = 1;
	for (int i = 0; i < vy.size(); i++) {
		for (int j = 0; j <= 16000; j++) dpY[(i + 1) % 2][j] = 0;
		for (int j = 0; j <= 16000; j++) {
			if (j + vy[i] <= 16000) dpY[(i + 1) % 2][j + vy[i]] |= dpY[i % 2][j];
			if (j - vy[i] >= 0) dpY[(i + 1) % 2][j - vy[i]] |= dpY[i % 2][j];
		}
	}
	if (dpX[vx.size() % 2][x + 8000] && dpY[vy.size() % 2][y + 8000]) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}