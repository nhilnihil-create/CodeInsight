#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define Rep(i, k, n) for (int i = k; i < (int)(n); i++)
#define RRep(i, k, n) for (int i = k; i > (int)(n); i--)
#define COUT(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl
#define ALL(a)  (a).begin(),(a).end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
const int MOD = 1000000007;
const double PI = acos(-1); //3.14~
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int n;
vector<vector<P> > g;
vector<int> ans;

void dfs(int v, int p, int c)
{
    ans[v] = c;
    for (auto e : g[v])
    {
        if (e.first == p) continue;
        if (e.second & 1) dfs(e.first, v, 1 - c); //odd
        else dfs(e.first, v, c); //even
    }
}

int main()
{
    cin >> n;
    g.assign(n, vector<P>());

    rep(i, n - 1)
    {
        int u, v, w; cin >> u >> v >> w; --u;--v;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    ans.assign(n, 0);
    dfs(0, -1, 1);
    for (auto v : ans) cout << v << endl;
}