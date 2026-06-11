#include <bits/stdc++.h>
typedef long long ll;
#define rep(i, a, b) for (ll i = a; i < (ll)b; ++i)
#define digit(a) to_string(a).size()
#define INF 10e12
#define MAX 51000
#define all(x) (x).begin(), (x).end()
#define MX(x) *max_element(all(x))
#define MN(x) *min_element(all(x))
using namespace std;
int main(void)

{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    string ans = "01";
    vector<vector<pair<ll, ll>>> v(n);
    rep(i, 0, n - 1)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    priority_queue<ll> q;
    vector<ll> dist(n, -1);
    q.push(0);
    dist[0] = 0;
    while (!q.empty())
    {
        auto tmp = q.top();
        q.pop();
        for (auto i : v[tmp])
        {
            if (dist[i.first] == -1) //未探索の場合
                dist[i.first] = dist[tmp] + i.second, q.push(i.first);
        }
    }
    rep(i, 0, n) cout << ans[dist[i] % 2] << endl;
}
