#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const LL MOD = 1000000007LL;
bool dpX[2][16001];
bool dpY[2][16001];
int main() {
	string s;
	cin >> s;
	int N = s.size();
	int X, Y;
	cin >> X >> Y;
	int pos = 0;
	while (pos < N && s[pos] == 'F') X--, pos++;
	bool dir = 1;
	int d = 0;
	vector<int> dx, dy;
	while (pos < N) {
		if (s[pos] == 'F') {
			d++;
		}
		else {
			if (dir) dx.push_back(d);
			else dy.push_back(d);
			dir ^= 1;
			d = 0;
		}
		pos++;
	}
	if (dir) dx.push_back(d);
	else dy.push_back(d);
	dpX[0][N] = 1;
	for (int i = 0; i < dx.size(); i++) {
		for (int x = -N; x <= N; x++) {
			if (x + dx[i] <= N) dpX[(i + 1) & 1][x + dx[i] + N] |= dpX[i & 1][x + N];
			if (x - dx[i] >= -N) dpX[(i + 1) & 1][x - dx[i] + N] |= dpX[i & 1][x + N];
			dpX[i & 1][x + N] = 0;
		}
	}
	dpY[0][N] = 1;
	for (int i = 0; i < dy.size(); i++) {
		for (int y = -N; y <= N; y++) {
			if (y + dy[i] <= N) dpY[(i + 1) & 1][y + dy[i] + N] |= dpY[i & 1][y + N];
			if (y - dy[i] >= -N) dpY[(i + 1) & 1][y - dy[i] + N] |= dpY[i & 1][y + N];
			dpY[i & 1][y + N] = 0;
		}
	}
	if (-N <= X && X <= N && -N <= Y && Y <= N && dpX[dx.size() & 1][X + N] && dpY[dy.size() & 1][Y + N]) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}