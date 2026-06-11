#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < n; i++)
#define repr(i, n) for(ll i = n; i >= 0; i--)
#define reprr(i, m, n) for (ll i = m; i < n; i++)
#define inf (1LL<<60)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
using Graph = vector<vector<pair<ll, ll>>>;


int main()
{
    ll N, M; cin >> N >> M;
    vector<pair<ll, ll>> v(M);
    rep(i, M) cin >> v[i].first >> v[i].second;
    sort(all(v));
    ll right = inf;
    ll count = 0;
    rep (i, v.size()) {
        auto p = v[i];
        //cout << p.first << " " << p.second << endl;
        if (p.first >= right) {
            count++;
            right = inf;
        }
        if (p == v[v.size()-1]) {
            count++;
            break;
        }

        right = min(right, p.second);
    }
    cout << count << endl;
    return 0;
}