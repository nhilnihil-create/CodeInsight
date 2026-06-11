#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
#include <cassert>
#include <random>

using namespace std;
typedef long long ll;

vector<int> g[101010];
int memo[101010];
bool flag = 0;
int cnt[2];

void dfs(int v, int color) {
    for (int nv : g[v]) {
        if (memo[nv] == color) {
            flag = 1;
            continue;
        } else if (memo[nv] == (color + 1) % 2) {
            continue;
        } else if (memo[nv] == -1) {
            int new_color = (color + 1) % 2;
            memo[nv] = new_color;
            cnt[new_color] += 1;
            dfs(nv, new_color);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 0; i < n; i++) {
        memo[i] = -1;
    }
    memo[0] = 0;
    cnt[0] = 1;
    cnt[1] = 0;
    dfs(0, 0);
    if (flag) {
        cout << (long long) n * (n-1) / 2 - m << endl;
    } else {
        cout << (long long) cnt[0] * cnt[1] - m << endl;
    }

    return 0;
}
