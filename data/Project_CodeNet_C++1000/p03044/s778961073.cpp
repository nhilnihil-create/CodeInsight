#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <functional>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000
const int MAX_V = 100010;
typedef pair<int, int> P;
vector<P> G[MAX_V];
int color[MAX_V];
int N; 
void dfs(int v, int p = -1, int depth = 0) {
    color[v] = depth % 2;
    for(auto to: G[v]) {
        if(p == to.first) continue;
        int d = depth + to.second;
        dfs(to.first, v, d);
    }
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    rep(i, N - 1) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--; w %= 2;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    dfs(0, 0);
    rep(i, N) {
        if(color[i] == 1) cout << 1 << endl;
        else cout << 0 << endl;
    }

    return 0;
}
