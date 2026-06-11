#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <iomanip>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define debug(x) cout << #x << " = " << x << endl
#define fori(i, ini, lim) for(int i = int(ini); i < int(lim); i++)
#define ford(i, ini, lim) for(int i = int(ini); i >= int(lim); i--)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

const int MAX = 1e5 + 5;
vector<int> adj[MAX];
bool visited[MAX];

void dfs(int x) {
    visited[x] = true;
    for (auto &each : adj[x]) if (!visited[each]) dfs(each);
}

void solve() {
    int n, m;
    cin >> n >> m;
    fori (i, 0, m) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans = 0;
    fori (i, 1, n + 1) {
        if (!visited[i]) {
            dfs(i);
            ans++;
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}

