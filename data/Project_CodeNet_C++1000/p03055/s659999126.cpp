#include <bits/stdc++.h>
using namespace std;

#define watch(x) cerr << (#x) << ": " << (x) << endl
#define int long long

const int N = 200000;
int n;
vector<int> graph[N+1];

void dfs(int cur, int par, int d, int& dist, int& deepest) {
    if(d > dist) {
        deepest = cur;
        dist = d;
    }
    for(int child : graph[cur]) {
        if(child != par) {
            dfs(child, cur, d+1, dist, deepest);
        }
    }
}

int findDiam() {
    int deepest = 1, dist = 0;
    dfs(1, 0, 0, dist, deepest);

    int ignore = 1, diam = 0;
    dfs(deepest, 0, 0, diam, ignore);
    return diam;
}

bool firstWins(int diam) {
    if(diam == 0) return true;
    int m = diam%3;
    return m == 0 || m == 2;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n-1; ++i) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int diam = findDiam();

    if(firstWins(diam)) {
        cout << "First\n";
    } else {
        cout << "Second\n";
    }
    
    return 0;
}
