#include <bits/stdc++.h>

using namespace std;
// a - b
// a inc b dec
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
//#define int ll
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef vector< vvi > vvvi;
typedef vector<short> vs;
typedef vector<vs> vvs;
typedef vector<vvs> vvvs;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef vector<ld> vld;
typedef vector<vld> vvld;
typedef vector<vvld> vvvld;
typedef pair<ld, ld> pld;
typedef complex<double> base;

#define mmin(a, b) a = min(a, (b))
#define mmax(a, b) a = max(a, (b))
#define mp(a,b) make_pair(a,b)
#define modsum(a, b) ((a) + (b) >= M ? (a) + (b) - M : (a) + (b))
#define modsubtract(a, b) ((a) - (b) < 0 ? (a) - (b) + M : (a) - (b))
#define modmultiply(a, b) (((a) * (b)) % M)
#define pb(a) push_back(a)
#define ALL(a) a.begin(),a.end()
#define sqr(x) (x) * (x)
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define cint const int &
#define SZ(a) ((int)(a.size()))
#define f(cnt) (((cnt) + 1) * (cnt) / 2)
#define watch(x) cout << (#x) << " = " << x << endl;
//#define log log10

const double PI = 2 * acos(0.0);

template<typename T>
struct edge {
    int from, to;
    T w;
    edge(int from, int to, T w): from(from), to(to), w(w) { }
    edge() { }
};


template<class T>
void show(T a) {
    for (auto x : a)
        cout << x << " ";
    cout << endl;
}

const int N = 2e5 + 9;


vector<edge<bool>> e;
vi g[N];
int n, m;
bool mark[N];
char used[2][N];

void dfs(int z, int v) {
    used[z][v] = 1;
    for (int id : g[v]) {
        int to = e[id].to;
        if (e[id].w != z) continue;
        if (used[!z][to] == 1) {
            cout << "Yes";
            exit(0);
        } else if (!used[!z][to]) dfs(!z, to);
    }
    used[z][v] = 2;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    string s;
    cin >> s;
    fori (i, n) {
        mark[i + 1] = s[i] == 'A';
    }
    fori (i, m) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(e.size());
        e.push_back(edge<bool>(u, v, mark[u] ^ mark[v]));
        g[v].push_back(e.size());
        e.push_back(edge<bool>(v, u, mark[u] ^ mark[v]));
    }

    for (int i = 1; i <= n; ++i) {
        for (int z = 0; z < 2; ++z) {
            if (!used[z][i]) dfs(z, i);
        }
    }
    cout << "No";
}