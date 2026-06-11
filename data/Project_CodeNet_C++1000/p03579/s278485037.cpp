/*
　　こんにちは。あたしはｶｳｶﾞｰﾙ。
　　redcoderになるためAtCoderを巡る旅をしてます。

　　　 　 ＿_
　　　 ヽ|＿_|ノ　　　　ﾓｫ
　　　　||‘‐‘||ﾚ　　_)_, ―‐ 、
　　　　/(Ｙ (ヽ＿ /・ ヽ　　 ￣ヽ
　　　　∠ ＿ ゝ　 ｀^ヽ ﾉ.::::_(ノヽ
　　　　 _/ヽ　 　　  /ヽ￣￣/ヽ
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define dump(x) cout << #x << " = " << (x) << endl
#define YES(n) cout << ((n) ? "YES" : "NO") << endl
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl
#define POSSIBLE(n) cout << ((n) ? "POSSIBLE" : "IMPOSSIBLE") << endl
#define Possible(n) cout << ((n) ? "Possible" : "Impossible") << endl

#define rep(i, n) REP(i, 0, n)                  // 0, 1, ..., n-1
#define REP(i, x, n) for(int i = x; i < n; i++) // x, x + 1, ..., n-1
#define FOREACH(x, a) for(auto &(x) : (a))

#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()

#define COUT(x) cout << (x) << endl

template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}

using Graph = vector<vector<int>>;

vector<int> color;

bool dfs(Graph &G, int v, int c) {
    color[v] = c;
    for(auto next_to : G[v]) {
        if(color[next_to] == c) return false;
        if(color[next_to] == 0 && !dfs(G, next_to, -c)) return false;
    }
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, M;
    cin >> N >> M;
    Graph G(N);
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    ll B = 0, W = 0;
    color.assign(N, 0);

    if(dfs(G, 0, 1)) {
        rep(i, N) {
            if(color[i] == 1) {
                B++;
            } else if(color[i] == -1) {
                W++;
            }
        }
        cout << B * W - M << endl;
    } else {
        cout << ((N * (N - 1)) / 2) - M << endl;
    }
}
