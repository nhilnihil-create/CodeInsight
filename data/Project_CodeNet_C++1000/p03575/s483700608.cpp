#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>
#include<iomanip>
#include<stack>
#include<string.h>
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define sz(a) (int)a.size()
using namespace std;

int n, m;

vector<vector<bool>> to;

vector<bool> visit;
void dfs(int now) {
	visit[now] = true;
	rep(i, n) {
		if (to[now][i] && !visit[i]) dfs(i);
	}
}

int main() {
	cin >> n >> m;
    to.resize(n,vector<bool>(n));
    visit.resize(n);
	vector<pair<int, int>> e(m);
	rep(i, m) {
		int ai, bi;
		cin >> ai >> bi;
		ai--; bi--;
		to[ai][bi] = true;
		to[bi][ai] = true;
		e[i] = { ai,bi };
	}
	int ans = 0;
	rep(i, m) {
		int ai = e[i].first;
		int bi = e[i].second;
		to[ai][bi] = false;
		to[bi][ai] = false;
		dfs(0);
		bool flag = false;
		rep(i, n) {
			if (!visit[i]) flag = true;
			visit[i] = false;
		}
		if (flag) ans++;
		to[ai][bi] = true;
		to[bi][ai] = true;
	}
	cout << ans << endl;
}