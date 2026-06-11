#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

vector<vector<int>> v;
int pnum[100100];

std::vector<std::vector<int>> iig(int vn, int en) {
	std::vector<std::vector<int>> res(vn);
        for(int i = 0; i < en; i++) {
                int s, t;
                std::cin >> s >> t;
                s--; t--;
                res[s].push_back(t);
		pnum[t]++;
        }
        return res;
}

int ans[100100];
int n, m;

void dfs(int i) {
	for(int j: v[i]) {
		if (--pnum[j] == 0) {
			ans[j] = i + 1;
		}
	}
	for(int j: v[i]) {
		if (pnum[j] == 0) dfs(j);
	}
}

int main() {
	cin >> n >> m;
	v = iig(n, n - 1 + m);
	int root;
	rep(i, n) if (pnum[i] == 0) {
		root = i;
		break;
	}
	dfs(root);
	rep(i, n) cout << ans[i] << endl;
}

