// https://atcoder.jp/contests/abc116/tasks/abc116_d
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define EPS (1e-9)
#define INF (1e9)
#define INFL (1e18)
#define MOD (1000000007)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPR(i, n) for (int i = (n - 1); i >= 0; --i)
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLR(obj) (obj).rbegin(), (obj).rend()
// ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
// ll lcm(ll c, ll d) { return c / gcd(c, d) * d; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<pii> v(n);
    REP(i, n) cin >> v[i].first >> v[i].second;
    // 第2引数を降順にする
    sort(ALL(v),
         [](const pii &x, const pii &y) { return x.second > y.second; });
    // 今までに出現したネタか判定する
    set<int> st;
    // ダブったネタの価値を小さい順に保存
    priority_queue<int, vector<int>, greater<int>> q;
    ll sum = 0;
    REP(i, k) {
        if (st.count(v[i].first) == 0) {
            st.insert(v[i].first);
        } else {
            q.push(v[i].second);
        }
        sum += v[i].second;
    }
    ll maxv = sum + st.size() * st.size();
    FOR(i, k, n) {
        if (q.empty())
            break;
        if (st.count(v[i].first) == 0) {
            st.insert(v[i].first);
            sum += v[i].second - q.top();
            q.pop();
            maxv = max(maxv, (ll)(sum + st.size() * st.size()));
        }
    }
    cout << maxv << endl;

    return 0;
}
