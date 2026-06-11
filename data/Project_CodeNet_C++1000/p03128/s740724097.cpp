#define _USE_MATH_DEFINES
 
#include <bits/stdc++.h> 
 
#define $(x) (int)((x).size())
#define endl '\n'
#define x first
#define y second
#define int long long
#define double long double
#define all(a) (a).begin(), (a).end()
 
#ifdef LOCAL
    #define dbg(x) cout << #x << " = " << x << endl;
#else 
    #define dbg(x)
#endif 
 
using namespace std;
 
void solve(); signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);                                       
    freopen("output.txt", "w", stderr);
#endif
    srand(time(0));
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(10);
    solve();    
}

const int MAXN = 10000 + 10, INF = 1e18;
int f[MAXN];
map<int, int> cost = {{1, 2}, {2, 5}, {3, 5}, {4, 4}, {5, 5},
                      {6, 6}, {7, 3}, {8, 7}, {9, 6}};
int n, m;
vector<int> dt;

void solve() {
    cin >> n >> m;
    dt.resize(m);
    for (int i = 0; i < m; ++i) {
        cin >> dt[i];
    }   

    for (int i = 1; i <= n; ++i) {
        f[i] = -INF;
    }
    for (int i = 1; i <= n; ++i) {
        for (auto k : dt) {
            if (i >= cost[k]) {
                f[i] = max(f[i - cost[k]] + 1, f[i]);
            }
        }
    }

    dbg(f[n]);

    int cur = n;
    for (int i = 0; i < f[n]; ++i) {
        int num = 0;
        for (auto k : dt) {
            if (cost[k] <= cur && f[cur - cost[k]] == f[cur] - 1 && k > num) {
                num = k;   
            }
        }
        cur -= cost[num];
        cout << num;
    }
}