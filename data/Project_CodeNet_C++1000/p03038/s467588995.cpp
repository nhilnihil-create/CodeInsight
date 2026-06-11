#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; ++i)
#define rep(i, n) repl(i, 0, n)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using G = vector<vector<int>>;
const int MOD = 1000000007;
const int INF = 1001001001;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, -1, 0, 1};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<int> b(m), c(m);
    rep(i, m) cin >> b[i] >> c[i];
    priority_queue<P> q;
    rep(i, n) {
        q.push(make_pair(a[i], 1));
    }
    rep(i, m) {
        q.push(make_pair(c[i], b[i]));
    }
    ll ans = 0;
    rep(i, n) {
        auto p = q.top();
        q.pop();
        ans += p.first;
        if(p.second > 1) {
            --p.second;
            q.push(p);
        }
    }
    cout << ans << endl;
    return 0;
}
