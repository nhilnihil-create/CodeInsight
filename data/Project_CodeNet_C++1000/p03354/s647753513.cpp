#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define REPV(iter, v) for(auto (iter)=(v).begin(); (iter)!=(v).end();++(iter))
#define ALL(v) (v).begin(),(v).end()

#define MOD 1000000007

using namespace std;

typedef long long ll;

struct UnionFind {
    vector<ll> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
    vector<ll> vSize;

    UnionFind(ll N) : par(N), vSize(N) { //最初は全てが根であるとして初期化
        for(ll i = 0; i < N; i++)
        {
            par[i] = i;
            vSize[i] = 1;
        }
    }

    ll root(ll x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(ll x, ll y) { // xとyの木を併合
        ll rx = root(x); //xの根をrx
        ll ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
        vSize[ry] += vSize[rx];
    }

    bool same(ll x, ll y) { // 2つのデータx, yが属する木が同じならtrueを返す
        ll rx = root(x);
        ll ry = root(y);
        return rx == ry;
    }

    ll size(ll x){    // データxが属する木の頂点数を得る
        ll rx = root(x);
        return vSize[rx];
    }
};

int main()
{
    ll N, M;
    cin >> N >> M;
    vector<ll> p(N);
    REP(i, N)
    {
        cin >> p[i];
        p[i]--;
    }

    UnionFind uf(N);
    REP(i, M)
    {
        ll x, y;
        cin >> x >> y;
        x--;
        y--;
        uf.unite(x, y);
    }
    ll ans = 0;
    REP(i, N)
    {
        if (uf.same(i, p[i]))
        {
            ans++;
        }
    }

    cout << ans << endl;
}
