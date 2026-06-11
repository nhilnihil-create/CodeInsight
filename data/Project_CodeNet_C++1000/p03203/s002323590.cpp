#include<iostream>
#include<string>
#include<algorithm>    
#include<cmath>
#include<map>
#include<vector>
#include<math.h>
#include<stdio.h>
#include<stack>
#include<queue>
#include<tuple>
#include<cassert>
#include<set>
#define int long long
using namespace std;
const int INF = 1000000000000;
const int mod = 1000000007;
signed main() {
	int n, m, k, cnt = 0; cin >> n >> m >> k;
	vector<vector<int>>test(n + 1);
	vector<vector<int>>aa(k, vector<int>(2));
	map<int, map<int, int>>maze;//障害物
	for (int h = 0; h < k; h++) {
		cin >> aa[h][0] >> aa[h][1];
		maze[aa[h][0]][aa[h][1]] = 1;
	}
	sort(aa.begin(), aa.end());
	for (int h = 0; h < k; h++) {
		test[aa[h][0]].push_back(aa[h][1]);
	}
	int saidai = 1;
	for (int h = 2; h <= n; h++) {
		if (maze[h][saidai + 1] != 1) { saidai++; }
		if ((test[h].empty() == false) && (test[h][0] < saidai)) {
			cout << h - 1 << endl; return 0;
		}
	}
	cout << n << endl;
	return 0;
}