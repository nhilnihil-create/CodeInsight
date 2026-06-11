#include <bits/stdc++.h>

using namespace std;

#define FOR(i,l,r) for (int i=(l); i<(r); ++i)
#define sz(x) (int)(x).size()
#define print(x) cout << (x) << endl
#define dbg(x) cout << (#x) << ' ' << (x) << endl
#define all(x) (x).begin(), (x).end()

typedef string str;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

/* ------ END OF TEMPLATE ------ */

const int maxn = 1e5 + 5;

int n, m, u, v, ret, dp[maxn];
vector<int> adj[maxn];

int rec(int u) {
    int &ret = dp[u];
    if (ret != -1) return ret;
    else ret = 0;
    for (int &v : adj[u])
        ret = max(ret, rec(v)+1);
    return ret;
}

int main() {
    scanf("%i%i",&n,&m);
    memset(dp, -1, sizeof dp);
    for (int i=0; i<m; i++) {
        scanf("%i%i",&u,&v);
        adj[u].push_back(v);
    }
    for (int i=1; i<=n; i++)
        ret = max(ret, rec(i));
    printf("%i\n",ret);
}