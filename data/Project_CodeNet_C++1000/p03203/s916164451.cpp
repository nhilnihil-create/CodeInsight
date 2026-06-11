#include <bits/stdc++.h>
using namespace std;

set<int> P[200055];

int H, W, N, Ans;

bool f(int y, int x) { return P[y].find(x) != P[y].end(); }
void upd(int t) { if(t < Ans) Ans = t; }

int main() {
	ios::sync_with_stdio(false);

	cin >> H >> W >> N;
	for(int i = 0, x, y; i < N; i++) {
		cin >> x >> y;
		P[y].insert(x);
	}
	for(int i = 1; i <= W; i++) P[i].insert(H+1);

	Ans = H;
	for(int y = 1, x = 1; y <= W; y++) {
		if(f(y, x+1)) {
			upd(x);
			break;
		}
		x++;
		upd(*P[y].lower_bound(x) - 1);
		if(y == W) break;
		for(; x <= H && f(y+1, x); x++);
		if(H < x) break;
	}

	cout << Ans << endl;
	return 0;
}