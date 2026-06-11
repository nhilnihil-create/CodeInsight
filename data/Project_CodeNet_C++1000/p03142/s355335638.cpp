#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
typedef pair<int, int> P;
int main()
{
    int N, M;
    cin >> N >> M;

    vector<vector<int>> G(N);
    vector<int> in(N, 0);
    rep(i, N + M - 1) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        in[v]++;
    }

    int root;
    rep(i, N) {
        if (in[i] == 0) root = i; 
    }

    vector<int> ans(N, -1);
    queue<int> V;
    V.push(root);
    
    while (!V.empty()) {
        int v = V.front(); V.pop();
        rep(i, G[v].size()) {
            int to = G[v][i];
            in[to]--;
            if (in[to] == 0) {
                V.push(to);
                ans[to] = v;
            }
        }
    }

    rep(i, N) cout << ans[i] + 1 << endl;

    return 0;
}