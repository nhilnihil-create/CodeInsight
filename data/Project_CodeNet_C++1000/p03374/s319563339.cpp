#include <bits/stdc++.h>

using namespace std;

#define int long long

const int INF = 1e18;

int get_last(multiset <int>& ms) {
    auto it = ms.end();
    --it;
    return *it;
}

int start(vector <pair <int, int> >& v, vector <pair <int, int> >& rv) {
    multiset <int> ms;
    int sum_v = 0;
    vector <int> del;
    for (auto it : rv) {
        sum_v += it.second;
        ms.insert(sum_v - it.first);
        del.push_back(sum_v - it.first);
    }
    reverse(del.begin(), del.end());
    int ans = get_last(ms);
    sum_v = 0;
    for (int i = 0; i < signed(v.size()) - 1; ++i) {
        sum_v += v[i].second;
        ms.erase(ms.find(del[i]));
        ans = max(ans, sum_v - 2 * v[i].first + get_last(ms));
    }
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, c;
    cin >> n >> c;
    vector <pair <int, int> > v(n), rv;
    for (auto& it : v) {
        cin >> it.first >> it.second;
    }
    for (int i = signed(v.size()) - 1; i >= 0; --i) {
        rv.push_back({c - v[i].first, v[i].second});
    }
    int ans = max(start(v, rv), start(rv, v));
    ans = max(ans, 0ll);
    cout << ans << "\n";
    return 0;
}