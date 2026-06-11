#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const int MOD = 1000000007;
const int INF = 2000000000;

vector<int> G[100000];
int V;
int color[100000];

bool dfs(int from, int c) {
    color[from] = c;
    for(int to : G[from]) {
        if(color[to] == c) return false;
        if(color[to] == 0 && !dfs(to, -c)) return false;
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    rep(i, m) {
        int a, b;
        cin >> a >> b;
        G[a - 1].pb(b - 1);
        G[b - 1].pb(a - 1);
    }
    
    V = n;
    rep(i, V) {
        color[i] = 0;
    }

    int b = 0, w = 0;
    if(dfs(0, 1)) {
        rep(i, V) {
            if(color[i] == 1) b++;
            else w++;
        }
        cout << (ll)b * w - m << endl;
    }else cout << (ll)n * (n - 1) / 2 - m << endl;

    return 0;
}

