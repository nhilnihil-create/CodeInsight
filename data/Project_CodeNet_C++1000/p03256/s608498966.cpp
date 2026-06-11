#define _FORTIFY_SOURCE 0
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")

#include<bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define int long long
#define double long double
#define pref pref228
#define left left228
#define right right228
#define x1 x1228
#define y1 y1228
#define all(x) x.begin(), x.end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
mt19937 rnd(time(0));

const int maxn = 3e5 + 7, mod = 1e9 + 7, inf = 1e18;
const double eps = 1e-9, pi = acos(-1);
int n, m; 
string have; 
vector<int> gr[maxn]; 
set<pii> kek; 

int A[maxn], B[maxn]; 

int use[maxn];
vector<int> path;

void dfs(int u) {
    use[u] = 1; 
    path.pb(u); 
    for (auto v : gr[u]) {
        if (!use[v]) dfs(v); 
    }
}

int use1[maxn]; 

bool bfs() {
    deque<int> q;   
    int d = 0; 
    for (auto v : path) {
        if (A[v] == 0 || B[v] == 0) { 
            q.pb(v);
            use1[v] = 1;                
            ++d;
        }
    }
    while (q.size()) {
        int v = q.front(); 
        q.pop_front();
        for (auto u : gr[v]) {
            if (have[v] == 'A') A[u]--; 
            else B[u]--; 

            if (!use1[u] && (B[u] == 0 || A[u] == 0)) {
                q.pb(u); 
                use1[u] = 1; 
                ++d;
            }
        }
    }
    if (d != path.size()) return true; 
    return false; 
}

void solve() {
    cin >> n >> m >> have; 
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;        
        --a, --b;
        if (a > b) swap(a, b); 
        if (kek.count(mp(a, b))) continue;
        kek.insert({a, b});
        gr[a].pb(b); 
        gr[b].pb(a); 
        if (have[b] == 'A') A[a]++;
        else B[a]++;

        if (have[a] == 'A') A[b]++; 
        else B[b]++; 
    }
    
    for (int i = 0; i < n; ++i) {
        if (!use[i]) {
            path.clear(); 
            dfs(i); 

            if (bfs()) {
                cout << "Yes";
                return; 
            } 
        }
    }        
    cout << "No";  
}                               

signed main() {
//  freopen("", "r", stdin);
//  freopen("", "w", stdout);
#ifdef offline_judge
    freopen("TASK.in", "r", stdin);
    freopen("TASK.out", "w", stdout);
#endif
    srand(time(0));
    cout.precision(10);
    cout << fixed;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
} 