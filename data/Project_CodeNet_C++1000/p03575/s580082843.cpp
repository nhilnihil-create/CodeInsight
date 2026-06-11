#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
#define PRINT(x) cout<<(x)<<endl
#define INF 1000000000000 // 10^12
#define MOD 1000000007 // 10^9+7
#define PB push_back
#define MP make_pair

const int MAX_N = 50, MAX_M = 50;

int N, M;
int a[MAX_M], b[MAX_M];

vector<int> G[MAX_N];
bool visited[MAX_N];

void dfs(int pos) {
    visited[pos] = true;
    REP(i, G[pos].size()) {
        int to = G[pos][i];
        if (visited[to]) continue;
        dfs(to);
    }
    return;
}

int main() {
    cin >> N >> M;
    REP(i, M) {
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
    }

    int num_bridge = 0;
    REP(i, M) {
        REP(j, N) {
            G[j] = {};
            visited[j] = false;
        }

        REP(j, M) {
            if (i == j) continue;
            G[a[j]].PB(b[j]);
            G[b[j]].PB(a[j]);
        }

        int cnt = 0;
        REP(j, N) {
            if (visited[j] == false) {
                dfs(j);
                cnt++;
            }
        }
        if (cnt != 1) num_bridge++;
    }
    PRINT(num_bridge);
    return 0;
}