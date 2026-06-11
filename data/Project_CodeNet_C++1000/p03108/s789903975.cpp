/*
　　こんにちは。あたしはｶｳｶﾞｰﾙ。
　　RedcoderになるためAtCoderを巡る旅をしてます。

　　　 　＿_
　　　 ヽ|＿_|ノ　　　　ﾓｫ
　　　　||‘‐‘||ﾚ　　_)_, ―‐ 、
　　　　/(Ｙ (ヽ＿ /・ ヽ　　   ￣ヽ
　　　　∠ ＿ ゝ　 ｀^ヽ ﾉ.::::_(ノヽ
　　　　 _/ヽ　 　　  /ヽ￣￣￣/ヽ
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

struct UnionFind {
    vector<int> data;
    UnionFind(int size) : data(size, -1) {}

    bool merge(int x, int y) {
        x = root(x);
        y = root(y);
        if(x == y) return false;
        if(data[y] < data[x]) swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return true;
    }

    int root(int x) { return data[x] < 0 ? x : (data[x] = root(data[x])); }

    int size(int x) { return -data[root(x)]; }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, M;
    cin >> N >> M;
    vector<ll> a(M), b(M);
    rep(i, M) {
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
    }

    UnionFind UF(N);
    vector<ll> ans(M, 0);
    ans[M - 1] = N * (N - 1) / 2;

    for(int i = M - 1; i > 0; i--) {
        if(UF.root(a[i]) == UF.root(b[i])) {
            ans[i - 1] = ans[i];
            continue;
        }
        ans[i - 1] = ans[i] - 1ll * UF.size(a[i]) * UF.size(b[i]);
        UF.merge(a[i], b[i]);
    }
    rep(i, M) COUT(ans[i]);
}
