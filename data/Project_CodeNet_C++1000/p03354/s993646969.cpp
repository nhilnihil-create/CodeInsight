#include <bits/stdc++.h>
using namespace std;
using ll         = long long;
constexpr ll MOD = 1000000007;
#define REP(i, n) for (ll i = 0; i < (n); i++)
#define REP2(i, x, n) for (ll i = x; i < (n); i++)
#define PR(x) cout << (x) << "\n"
#define PS(x) cout << (x) << " "
#define PRYES(x) PR((x) ? "Yes" : "No")
const long long INF = numeric_limits<long long>::max();

// 双方向の関係性をグループにまとめられるやつ
// https://atcoder.jp/contests/abc177/tasks/abc177_d
class UnionFind {
    //自身が親であれば、その集合に属する頂点数に-1を掛けたもの
    //そうでなければ親のid
public:
    vector<ll> datas;
    UnionFind(ll N) : datas(N, -1) {
    }
    // 該当の値が根か
    bool isRoot(ll x) const {
        return datas[x] < 0;
    }
    // 根の情報を更新/取得
    ll root(ll x) {
        if (isRoot(x)) return x;
        // Rootの情報を更新する
        datas[x] = root(datas[x]);
        return datas[x];
    }

    // 値a,bを関連付け
    bool unite(ll x, ll y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (datas[x] > datas[y]) swap(x, y);
        datas[x] += datas[y];
        datas[y] = x;
        return true;
    }

    // 該当の根に相当するデータサイズを取得
    ll size(ll x) {
        return -datas[root(x)];
    }

    // 該当の値の根が同じかを判定
    bool same(ll a, ll b) {
        return root(a) == root(b);
    }

    void Dump() {
#ifdef SOURCE_TEST
        REP(i, datas.size()) {
            if (isRoot(i)) {
                PS("Root:");
                PS(size(i));
            } else {
                cout << datas[i] << ":";
            }

            PR(i);
        }
#endif
    }
};

int main() {
    ll N, M;

    cin >> N >> M;

    vector<ll> values(N);
    REP(i, N) {
        cin >> values[i];
    }

    UnionFind unionFind(N);
    REP(i, M) {
        ll x, y;
        cin >> x >> y;
        unionFind.unite(x - 1, y - 1);
    }

    ll count = 0;
    REP(i, N) {
        if (unionFind.same(i, values[i] - 1)) {
            count++;
        }
    }
    PR(count);
    return 0;
}