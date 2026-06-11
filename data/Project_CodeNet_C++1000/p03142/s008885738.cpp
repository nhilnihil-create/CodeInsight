// https://www.youtube.com/watch?v=UWbGRhF3Ozw
// https://atcoder.jp/contests/abc139/submissions/7330266
// https://qiita.com/drken/items/23a4f604fa3f505dd5ad#4-3-dag-%E3%81%AE%E3%83%88%E3%83%9D%E3%83%AD%E3%82%B8%E3%82%AB%E3%83%AB%E3%82%BD%E3%83%BC%E3%83%88
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B
#include <bits/stdc++.h>
#define REP(i, n) for(ll i = 0; i < (ll)n; i++)
#define FOR(i, a, b) for(ll i = (a); i < (ll)b; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF (1ll << 60)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
using vl = vector<ll>;
using vvl = vector<vl>;
typedef double db;
typedef string str;
typedef pair<ll, ll> p;
constexpr int MOD = 1000000007;
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;

class DAG {
  private:
    ll v, e;

    vector<ll> in_d; // 頂点の入力次数
    vector<ll> head;

  public:
    // v: 頂点数
    // e: 辺の数
    vector<vector<ll>> table;
    DAG(ll v) : v(v) {
        table.resize(v);
        in_d.resize(v);
        e = 0;
    }

    void add(ll from, ll to) {
        table[from].emplace_back(to);
        in_d[to]++;
        e++;
    }

    // O(v + e)
    vl sort() {
        stack<ll> st; // 入力次数が0の頂点集合
        for(int i = 0; i < v; i++) {
            if(in_d[i] == 0) {
                st.push(i);           // stack
                head.emplace_back(i); // head
            }
        }
        vl ans; // ソート後のグラフ

        while(!st.empty()) {
            ll in = st.top();
            st.pop();
            ans.emplace_back(in);
            for(auto &j : table[in]) {
                in_d[j]--;
                if(in_d[j] == 0)
                    st.push(j);
            }
        }

        return move(ans);
    }

    ll get_longest_path(void) {
        vector<bool> seen(v), calc(v);
        vector<ll> d(v, 0);
        auto dfs = [&](auto &&f, ll now) -> ll {
            if(seen[now]) {
                if(!calc[now])
                    return -1;
                return d[now];
            }
            seen[now] = true;
            d[now] = 1;
            for(auto &t : table[now]) {
                ll res = f(f, t);
                if(res == -1)
                    return -1;
                d[now] = max(res + 1, d[now]);
            }
            calc[now] = true;
            return d[now];
        };

        ll ans = 0;
        for(int i = 0; i < v; i++) {
            ll tmp = dfs(dfs, i);
            if(tmp == -1) {
                return -1;
            }
            ans = max(tmp, ans);
        }
        return ans;
    }
};

int main(void) {
    ll n, m;
    cin >> n >> m;
    DAG dag(n + m - 1);
    REP(i, n + m - 1) {
        ll s, t;
        cin >> s >> t;
        s--;
        t--;
        dag.add(s, t);
    }
    vl sorted = dag.sort();
    map<ll, ll> order;
    REP(i, sorted.size()) { order[sorted[i]] = i + 1; }
    vvl table = dag.table;
    vl ans(n);
    vl ans_order(n); //親の順番
    for(ll i = 0; i < n; i++) {
        for(auto e2 : table[i]) {
            if(ans_order[e2] < order[i]) {
                ans_order[e2] = order[i];
                ans[e2] = i + 1;
            }
        }
    }
    REP(i, n) cout << ans[i] << endl;
    return 0;
}
