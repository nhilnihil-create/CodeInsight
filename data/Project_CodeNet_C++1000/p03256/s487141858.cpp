#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define rep(i, n) FOR(i, 0, n)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;

constexpr int Mod = 998244353;
constexpr int mod = 1e9 + 7;
constexpr ll inf = 1LL << 60;

template <typename T> constexpr bool chmax(T &a, const T &b) {
    if(a >= b) return false;
    a = b;
    return true;
}
template <typename T> constexpr bool chmin(T &a, const T &b) {
    if(a <= b) return false;
    a = b;
    return true;
}

/*-------------------------------------------*/

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    ll N, M;
    cin >> N >> M;
    string s;
    cin >> s;
    vector<vector<int>> G(N);
    vector<int> cntA(N), cntB(N);

    rep(i, M) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
        (s[a] == 'A' ? cntA[b] : cntB[b])++;
        (s[b] == 'A' ? cntA[a] : cntB[a])++;
    }

    queue<int> que;
    rep(i, N) if(!cntA[i] || !cntB[i]) que.push(i);

    while(!que.empty()) {
        N--;
        int v = que.front();
        que.pop();
        vector<int> &vec = (s[v] == 'A' ? cntA : cntB);
        for(int u : G[v]) {
            if(!cntA[u] || !cntB[u]) continue;
            if(--vec[u] == 0) que.push(u);
        }
    }

    cout << (N ? "Yes" : "No");

    return 0;
}