#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

int main()
{
    int N, K; cin >> N >> K;
    vector<pii> dt(N); // fitst:d, second:t
    for (auto& e : dt) cin >> e.second >> e.first;
    sort(dt.begin(), dt.end(), greater<pii>());

    map<int, int> m; // key: t, value:count...
    auto compare = [&](const pii& a, const pii& b) {
        const int& at = a.second, ad = a.first;
        const int& bt = b.second, bd = b.first;
        if (at != bt) {
            int ca = m[at], cb = m[bt];
            if (ca >= 2 && cb >= 2) {
                return bd < ad;
            } else if (ca >= 2) {
                return false;
            } else if (cb >= 2) {
                return true;
            }
        }
        return bd < ad;
    };
    priority_queue<pii, vector<pii>, decltype(compare)> q(compare);

    ll ans = 0;
    ll s = 0;
    for (int i = 0; i < K; i++) {
        m[dt[i].second]++;
        q.push(dt[i]);
        s += dt[i].first;
    }
    int vars = m.size();
    ans = s + (ll)vars * vars;

    int ind = K;
    for (int v = vars + 1; v <= K; v++) {
        ll a = 0;

        pii p = q.top();
        if (m[p.second] < 2) break;

        while (ind < N) {
            if (m[dt[ind].second] == 0) break;
            ind++;
        }
        if (ind == N) break;

        m[p.second]--;
        q.pop();
        m[dt[ind].second]= 1;
        q.push(dt[ind]);
        s = s - p.first + dt[ind].first;

        a = s + (ll)v * v;
        ans = max(ans, a);
    }

    cout << ans << endl;
}
