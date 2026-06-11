//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define db long double
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define mp make_pair
#define all(x) (x).begin(), (x).end()

void dout() { cerr << '\n'; }

template <typename Head, typename... Tail>
void dout(Head H, Tail... T) {
    cerr << " " << H;
    dout(T...);
}

#ifdef LOCAL
    #define dbg(...) cerr << #__VA_ARGS__, dout(__VA_ARGS__)
#else
    #define dbg(...) ;
#endif

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef pair <int, int> pii;

const int N = 2e5 + 123;
int n, m, a[N], b[N], used[N];
char c[N];
vector <int> adj[N];

void add(int x, int y) {
    if (c[y] == 'A') {
        a[x]++;
    }
    if (c[y] == 'B') {
        b[x]++;
    }
}

void del(int x, int y) {
    if (c[y] == 'A') {
        a[x]--;
    }
    if (c[y] == 'B') {
        b[x]--;
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    int x, y;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
        add(x, y);
        if (y != x) {
            add(y, x);
        }
    }
    set <pii> st;
    for (int i = 1; i <= n; i++) {
        st.insert({min(a[i], b[i]), i});
    }
    pii v;
    while (!st.empty()) {
        v = *st.begin();
        st.erase(v);
        used[v.se] = 1;
        if (v.fi > 0) {
            cout << "Yes";
            return 0;
        }
        for (int to : adj[v.se]) {
            if (used[to]) {
                continue;
            }
            st.erase({min(a[to], b[to]), to});
            del(to, v.se);
            st.insert({min(a[to], b[to]), to});
        }
    }
    cout << "No";
}
