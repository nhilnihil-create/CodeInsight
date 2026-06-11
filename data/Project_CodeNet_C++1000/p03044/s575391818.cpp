#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define MAXN 100001
vector<vector<pair<ll, ll> > > vec(MAXN);
bool white[MAXN];
bool used[MAXN];
void dfs(int x, bool is_white) {
    used[x] = true;
    white[x] = is_white;
    for (int i = 0; i < vec[x].size(); i++) {
        if (!used[vec[x][i].first]) {
            if (vec[x][i].second % 2) {
                dfs(vec[x][i].first, !is_white);
            }
            else {
                dfs(vec[x][i].first, is_white);
            }
        }
    }
    used[x] = false;
}
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n - 1; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        vec[u].push_back(make_pair(v, w));
        vec[v].push_back(make_pair(u, w));
    }
    memset(used, false, sizeof(used));
    dfs(1, true);
    for (int i = 1; i <= n; i++) {
        if (white[i]) {
            cout << '0' << endl;
        }
        else {
            cout << '1' << endl;
        }
    }
    return 0;
}