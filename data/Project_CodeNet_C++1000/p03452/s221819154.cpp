#include <bits/stdc++.h>

using namespace std;

#define llong long long int
#define ldouble long double
#define ternary(condition, x, y) ((condition) ? x : y) 
#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) x.begin(), x.end()
#define stl_rep(itr, x) for (auto itr = x.begin(); itr != x.end(); ++itr)

const static llong MOD = 1000000000 + 7;
const static int dy[] = {0, 1, 0, -1};
const static int dx[] = {1, 0, -1, 0};

const static int N = 100000;
int visit[N + 1] = {}, sum_cost[N + 1] = {};
vector<vector<pair<int, int> > > G(N + 1);

int dfs(int x) {
    visit[x] = 1;

    for(size_t i = 0; i < G[x].size(); i++) {
        if (visit[G[x][i].first]) {
            if (sum_cost[G[x][i].first] != sum_cost[x] + G[x][i].second) return 0;
        } else {
            sum_cost[G[x][i].first] = sum_cost[x] + G[x][i].second;
            if (dfs(G[x][i].first) == 0) return 0;
        }
    }
    return 1;
}

int main (int argc, char *argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    int l, r, d;
    rep(i, m) {
        cin >> l >> r >> d;
        G[l].push_back(make_pair(r, d));
        G[r].push_back(make_pair(l, -d));
    }

    for (int i = 1; i <= n; ++i) {
        if (dfs(i) == 0) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    return 0;
}