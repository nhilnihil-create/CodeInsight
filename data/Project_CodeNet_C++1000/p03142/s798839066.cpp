#include <bits/stdc++.h>
using namespace std;

#define REP(i, m, n) for (int i = (m); i < (int)(n); i++)
#define REPS(i, m, n) for (int i = (m); i <= (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
#define reps(i, n) for (int i = 0; i <= (int)(n); i++)
#define rrep(i, x) for (int i = ((int)(x)-1); i >= 0; i--)
#define rreps(i, x) for (int i = (int)(x); i >= 0; i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> P;
const int inf = INT_MAX;
const ll INF = 1LL << 60;
const ll mod = 1e9 + 7;
const double EPS = 1e-10;
const double PI = acos(-1.0);
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename A, size_t N, typename T> void Fill(A (&array)[N], const T &val) { fill( (T*)array, (T*)(array+N), val ); }

vector<int> g[100010];
int h[100010];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    vector<int> A(N-1+M), B(N-1+M);
    rep(i, N-1+M) {
        cin >> A[i] >> B[i];
        A[i]--; B[i]--;
        g[A[i]].pb(B[i]);
        h[B[i]]++;
    }
    int parent = -1;
    rep(i, N) if (h[i] == 0) parent = i;

    vector<int> dist(N);
    queue<int> q;
    q.push(parent);
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        rep(i, g[v].size()) {
            int u = g[v][i];
            h[u]--;
            dist[u] = max(dist[u], dist[v] + 1);
            if (h[u] == 0) {
                q.push(u);
            }
        }
    }
    vector<int> par(N, -1);
    rep(i, N-1+M) {
        int f = A[i];
        int to = B[i];
        if (dist[to] - dist[f] == 1) {
            par[to] = f;
        }
    }
    rep(i, N) cout << par[i] + 1 << endl;
    return 0;
}