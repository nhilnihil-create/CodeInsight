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
#include<cstring>
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define sz(a) (int)a.size()
using namespace std;

ll inf = 1e9 + 7;

vector<vector<int>> to;
vector<bool> seen;

void dfs(int now) {
	seen[now] = true;
	rep(i, sz(to[now])) {
		if (!seen[to[now][i]]) dfs(to[now][i]);
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	to.resize(n);
	seen = vector<bool>(n, false);
	rep(i, m) {
		int xi, yi, zi;
		cin >> xi >> yi >> zi;
		xi--; yi--;
		to[xi].push_back(yi);
		to[yi].push_back(xi);
	}
	int ans = 0;
	rep(i, n) {
		if (!seen[i]) {
			ans++;
			dfs(i);
		}
	}
	cout << ans << endl;
}