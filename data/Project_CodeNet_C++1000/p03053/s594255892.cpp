
// A - Darker and Darker

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;


char field[1000][1000];
bool visited[1000][1000];

struct Loc {
	int r;
	int c;
	int step;
};

// 四方向への移動ベクトル
const int dr[4] = {1, 0, -1, 0};
const int dc[4] = {0, 1, 0, -1};

int bfs(int H, int W) {

	queue<Loc> search_queue;

	for (int r=0; r<H; r++) {
		for (int c=0; c<W; c++) {
			if (field[r][c] == '#') {
				search_queue.push(Loc{r, c, 0});
				visited[r][c] = true;
			}
		}
	}

	int max_step = 0;

	while(!search_queue.empty()) {
		// キューから探索対象の位置情報を取り出す
		Loc loc = search_queue.front();
		search_queue.pop();

		int r = loc.r;
		int c = loc.c;
		int step = loc.step;
		max_step = max(max_step, step);
		//cout << r << ' ' << c << " (" << s << ")" << endl; // **** debug ****

		// 四方向の探索を予約
		for (int dir = 0; dir < 4; dir++) {
			int next_r = r + dr[dir];
			int next_c = c + dc[dir];

			if (next_r < 0 || next_r >= H || next_c < 0 || next_c >= W) continue;
			if (visited[next_r][next_c]) continue;
			search_queue.push(Loc{next_r, next_c, step + 1});
			visited[next_r][next_c] = true;
		}
	}

	return max_step;
}

int main(){
	int H, W;
	cin >> H >> W;

	for (int r=0; r<H; r++) {
		for (int c=0; c<W; c++) {
			cin >> field[r][c];
		}
	}

	int ans = bfs(H, W);

	cout << ans << endl;

	return 0;
}