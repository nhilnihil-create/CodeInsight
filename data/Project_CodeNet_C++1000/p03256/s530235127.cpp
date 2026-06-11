#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef tuple<ll, ll, ll> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
#define REP(i,n) for (ll i = 0; i < n; ++i)
#define REPR(i,n) for (ll i = n-1; i >= 0; --i)
#define FOR(i,m,n) for (ll i = m; i < n; ++i)
#define FORR(i,m,n) for (ll i = n-1; i >= m; --i)
#define FORE(x,xs) for (const auto& x : xs)
#define FORI(i,v) for (auto i = v.begin(); i != v.end(); i++)
#define ALL(v) v.begin(), v.end()
#define CHMIN(x,y) x = min(x, y)
#define CHMAX(x,y) x = max(x, y)
#define YES(b) cout << (b ? "YES" : "NO") << endl
#define Yes(b) cout << (b ? "Yes" : "No") << endl

const int MAX = 2e5+10;

ll N, M;
string S;
set<int> adj[MAX];
int A[MAX], B[MAX];

bool solve() {
    set<int> rm;
    REP (i, N) {
        FORI (iter, adj[i]) {
            if (S[*iter] == 'A') A[i]++;
            else B[i]++;
        }
        if (A[i] == 0 || B[i] == 0) rm.insert(i);
    }

    int count = 0;
    while (!rm.empty()) {
        count++;
        int n = *rm.begin();
        rm.erase(rm.begin());

        FORI (iter, adj[n]) {
            int e = *iter;
            if (e == n) continue;
            adj[e].erase(adj[e].find(n));
            if (S[n] == 'A') A[e]--;
            else B[e]--;
            if (A[e] == 0 || B[e] == 0) rm.insert(e);
        }
    }

    return count != N;
}

int main() {
    cin >> N >> M >> S;
    REP (i, M) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].insert(b);
        adj[b].insert(a);
    }
    Yes(solve());
}