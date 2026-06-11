#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <numeric>
#include <queue>
#include <map> 
#include <set>
#include <string>
#include <functional>
#include <list>
#include <random>
#include <time.h>
#include <iomanip>
#include <assert.h>
#define int long long
#define double long double
#define oku7 1000000007
#define MAXN (int)1e+5 * 2+1
#define LL_MAX 9223372036854775807	//ない環境用
#define LL_HALFMAX 9223372036854775807 / 2	//ない環境用

using namespace std;
std::mt19937 mt((int)time(0));

int dx[4] = { 0, 1, 0, -1 }; // x軸方向への変位
int dy[4] = { 1, 0, -1, 0 }; // y軸方向への変位

vector<pair<int,int>> G[100002];

int x[100002];
int cnt = 0;
void dfs(int id) {
	//繋がってるノードをぜんぶ展開
	for (pair<int, int> p : G[id]) {
		//未訪問なら
		if (x[p.first] == LL_HALFMAX) {
			x[p.first] = x[id] + p.second;
			dfs(p.first);
		}
		//訪問済みなら
		else {
			//矛盾検査
			if (x[p.first] - x[id] != p.second) cnt++;
		}
	}
}

signed main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int l, r, d;
		cin >> l >> r >> d;
		G[l].push_back(make_pair(r, d));
		G[r].push_back(make_pair(l, -d));
	}

	//絶対に取らない値(未訪問)でxを初期化
	for (int i = 0; i < 100002; i++) x[i] = LL_HALFMAX;

	//非連結な場合も考えて全点スタートのdfs
	for (int i = 0; i < 100002; i++) {
		if (x[i] != LL_HALFMAX) continue;
		x[i] = 0;
		dfs(i);
	}
	if (cnt == 0) cout << "Yes\n";
	else cout << "No\n";

	return 0;
}