// #include <bits/stdc++.h>
#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#define PI 3.14159265358979323846264338327950288
#define rep(i,n) for(int i=0;i<n;i++)
#define exf(x)	 for(auto&& tmp : x) { cout << tmp << endl; }	// 拡張for
#define testP	 cout << "------------------ test ------------------" << endl;	// 動作確認テスト
#define testX(x) cout << "testout : " << x << endl;	// テストアウト
typedef long long ll;
using namespace std;
const int MOD{ int(1e9 + 7) };	// = 1000000007
const int inf{ 2100000000 };	// = 2100000000 (MAX:2147483647)

// ------------------ ベクター表示 ------------------ //
void printVec(vector<int>& vec) {
	cout << "";
	for (auto it = vec.begin(); it != vec.end(); it++) cout << *it << " ";
	cout << endl;
}

// ------------------ ベクター合計 ------------------ //
int sumVec(vector<int> v) {
	int sum = 0;
	for (size_t i = 0; i < v.size(); i++) sum += v[i];
	return sum;
}

// -------------------------------------------------- //
// ------------------ ここから本編 ------------------ //
// -------------------------------------------------- //

int main(void) {

	int H, W;
	cin >> H >> W;

	static char maze[50][50];
	fill(maze[0], maze[50], '-');
	int white = 0;
	rep(i, H) {
		rep(j, W) {
			cin >> maze[i][j];
			if (maze[i][j] == '.') white++;
		}
	}

	// ----------------------
	
	int dx[4] = { 1,0,-1,0 },
		dy[4] = { 0,1,0,-1 };
	int cnt[50][50] = { 0 };

	queue<pair<int, int>> que;
	que.push(make_pair(0, 0));

	while (!que.empty()) {
		pair<int,int> tmp = que.front();
		que.pop();

		rep(n, 4) {
			int nextY = tmp.first + dy[n],
				nextX = tmp.second + dx[n];

			if (nextY < 0 || nextY >= H || nextX < 0 || nextX >= W) continue;
			if (maze[nextY][nextX] == '#') continue;
			if (cnt[nextY][nextX] != 0) continue;
			
			cnt[nextY][nextX] = cnt[tmp.first][tmp.second] + 1;
			que.push(make_pair(nextY, nextX));
		}

	}

	// ----------------------

	if (cnt[H - 1][W - 1] == 0) cout << "-1" << endl;
	else cout << white - (cnt[H - 1][W - 1] + 1) << endl;
	
	return 0;
}
