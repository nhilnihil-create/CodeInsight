#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) REP(i, 0, n)
#define rrep(i, n) for (int i = (int)(n-1); i >= 0; i--)
#define sz(x) int(x.size())
#define bitsz(x) int(__builtin_popcount(x))
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define INF 2e9
#define LINF 1e18
#define mod 1000000007
template<class T> inline bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
typedef pair<int, int> P;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int n;
vector<int> dist; //根からの距離のパリティ
vector<vector<P>> G;

void dfs(int v, int d) {
    dist[v] = d;
    for (auto u : G[v]) {
        if (dist[u.first] == -1) {
            dfs(u.first, (d+u.second)%2);
        }
    }
}

int main() {
    cin >> n;
    dist.resize(n); G.resize(n);
    rep(i,n) dist[i] = -1; //未訪問なら-1
    rep(i,n-1) {
        int a,b,c; cin >> a >> b >> c;
        a--; b--;
        c %= 2;
        G[a].push_back(P(b,c));
        G[b].push_back(P(a,c));
    }
    dfs(0,0);
    rep(i,n) cout << dist[i] << endl;
}