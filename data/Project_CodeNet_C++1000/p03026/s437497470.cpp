#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i) 
#define PI acos(-1)

using namespace std;
using ll = long long;
using P = pair<int, int>;
using LP = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n;
    cin>>n;
    vector<vector<ll>> es(n);
    vector<LP> ps(n - 1);
    rep(i, n - 1) {
        ll e1, e2;
        cin>>e1>>e2; e1--; e2--;
        es[e1].push_back(e2);
        es[e2].push_back(e1);
        ps[i] = LP(e1, e2);
    }
    vector<ll> cs(n);
    rep(i, n) cin>>cs[i];
    sort(cs.begin(), cs.end());

    vector<ll> vs(n);
    vector<ll> visited(n);
    vector<ll> selected(n);
    priority_queue<LP, vector<LP>, greater<LP>> q;
    rep(i, n) q.emplace(es[i].size(), i);
    int i = 0;
    while (!q.empty()) {
        LP p = q.top(); q.pop();
        ll f = p.first;
        ll s = p.second;
        if (visited[s]) continue;
        visited[s] = cs[i];
        i++;

        for (auto e : es[s]) {
            selected[e]++;
            q.emplace(es[e].size() - selected[e], e);
        }
    }

    ll ans = 0;
    rep(i, n - 1) {
        ans += min(visited[ps[i].first], visited[ps[i].second]);
    }
    cout<<ans<<endl;
    rep(i, n) cout<<visited[i]<<endl;
}