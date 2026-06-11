#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000
typedef pair<ll, ll> pll;
typedef pair<int, int> pint;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> G(N, vector<int>());
    vector<pll> H;
    map<pll, int> hen;
    map<ll, ll> ma;
    vector<ll> c(N);
    rep(i, N - 1) {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    rep(i, N) { cin >> c[i]; }

    sort(all(c), greater<ll>());
    queue<int> que;
    vector<ll> d(N, -1);
    int cur = 0;
    ll ans = 0;
    que.push(0);
    d[0] = c[cur];
    while (!que.empty()) {
        int v = que.front(); // キューから先頭頂点を取り出す
        que.pop();

        // v から辿れる頂点をすべて調べる
        for (int nv : G[v]) {
            if (d[nv] != -1)
                continue; // すでに発見済みの頂点は探索しない

            // 新たな白色頂点 nv について距離情報を更新してキューに追加する
            d[nv] = c[cur + 1];
            ans += d[nv];
            que.push(nv);
            cur++;
        }
    }

    cout << ans << endl;
    rep(i, N) { cout << d[i] << " "; }
}