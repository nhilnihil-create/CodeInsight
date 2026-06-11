#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr long double EPS = 1e-15;
const long double PI = acos(-1);
constexpr int inf = 1e9;
constexpr ll INF = 2e18;
constexpr ll MOD = 1e9+7;
constexpr ll MOD1 = 998244353;
typedef pair<ll,ll> P;
//#define all(v) (v).begin(), (v).end()
#define rep(i,a,b) for (int i = (a); i < (b); i++)
#define REP(i,n) rep(i,0,n)
#define sz(s) (s).size()
#define pb push_back
#define fi first
#define se second
//#define mp make_pair

int n;
vector<int> G[200010];

void input() {
    cin >> n;
    REP(i,n-1) {
        int from,to;
        cin >> from >> to;
        from--;
        to--;
        G[from].pb(to);
        G[to].pb(from);
    }
}

int d[200010];

void f(int v, int depth) {
    if (d[v] != -1) return;
    d[v] = depth;
    for (int i = 0; i < G[v].size(); i++) {
        f(G[v][i], depth + 1);
    }
}

void solve() {
    REP(i,n) {
        d[i] = -1;
    }
    f(0,0);

    int ma = -1, id = -1;
    for (int i = 0; i < n; i++) {
        if (d[i] > ma) {
            ma = d[i];
            id = i;
        }
    }
    REP(i,n) {
        d[i] = -1;
    }
    f(id,0);

    int k = 0;
    for (int i = 0; i < n; i++) {
        k = max(k,d[i]);
    }

    if (k % 3 == 1) {
        cout << "Second" << endl;
    } else {
        cout << "First" << endl;
    }
}

int main(int argc, char *argv[]){
    input();
    solve();
    return 0;
}
