#include <bits/stdc++.h>
using namespace std;

#define MAX 200
#define WHITE 0
#define BLACK 1

int main() {
	int H, W;
	int c[10][10];
	int A[MAX][MAX];
	cin >> H >> W;
	for (int i = 0; i <= 9; i++) {
		for (int j = 0; j <= 9; j++) {
			cin >> c[i][j];
		}
	}
	// Optimize minimum cost c[i][j]
	int cto1[10];
	int col[] = {WHITE, WHITE, WHITE, WHITE, WHITE,
				 WHITE, WHITE, WHITE, WHITE, WHITE};
	priority_queue<pair<int, int>> PQ;	// cost, current location
	PQ.push(make_pair(-0, 1));
	while (!PQ.empty()) {
		auto u = PQ.top();
		PQ.pop();
		if (col[u.second] == WHITE) {
			col[u.second] = BLACK;
			cto1[u.second] = -u.first;
			for (int i = 0; i <= 9; i++) {
				PQ.push(make_pair(u.first - c[i][u.second], i));
			}
		}
	}
	int ans = 0;
	for (int h = 0; h < H; h++) {
		for (int w = 0; w < W; w++) {
			int a;
			cin >> a;
			ans += (a == -1 ? 0 : cto1[a]);
		}
	}
	cout << ans << endl;
	return 0;
}
