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
#include <numeric>
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

int x[101], y[101], h[101];

int a[100001], b[2001][2001], sum[100001];

int G[1001][1001];
vector<int> ans[1001];

signed main() {
	int N;
	cin >> N;
	//考える時間が惜しいのでO(N)でできるかどうか判別
	bool flag = false;
	int nodenum = 0;
	for (int i = 0; i < 10000; i++) {
		if (N == i * (i - 1) / 2) {
			flag = true;
			nodenum = i;
			break;
		}
	}
	if (!flag) {
		cout << "No\n";
		return 0;
	}
	//cout << nodenum << "\n";
	//nodenum個の完全グラフを構築
	for (int i = 1; i <= nodenum; i++) {
		for (int j = 1; j <= nodenum; j++) {
			if (i == j) continue;
			G[i][j] = G[j][i] = 1;
		}
	}
	int cnt = 1;
	for (int i = 1; i <= nodenum; i++) {
		for (int j = 1; j <= nodenum; j++) {
			if (i == j) continue;
			if (G[i][j] == 1) {
				ans[i].push_back(cnt);
				ans[j].push_back(cnt);
				G[i][j] = G[j][i] = 0;
				cnt++;
			}
		}
	}
	vector<vector<int>> kotae;
	for (int i = 1; i <= nodenum; i++) {
			if (ans[i].size() != 0) {
				kotae.push_back(ans[i]);
			}
	}
	cout << "Yes\n";
	cout << kotae.size() << "\n";
	for (vector<int> v : kotae) {
		cout << v.size() << " ";
		for (int i = 0; i < v.size(); i++) {
			cout << v[i];
			if (i != v.size() - 1) cout << " ";
			else cout << "\n";
		}

	}


	return 0;
}