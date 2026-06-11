#include <bits/stdc++.h>
using namespace std;

const int64_t inf = 1e18;

vector < int64_t > s, t;

pair < int64_t, int64_t > closest_shrine (int64_t x) {
    auto it = upper_bound(s.begin(), s.end(), x);
    if (it == s.begin())
        return make_pair(-inf, *it);
    else if (it == s.end())
        return make_pair(*prev(it), inf);
    else
        return make_pair(*prev(it), *it);
}

pair < int64_t, int64_t > closest_temple (int64_t x) {
    auto it = upper_bound(t.begin(), t.end(), x);
    if (it == t.begin())
        return make_pair(-inf, *it);
    else if (it == t.end())
        return make_pair(*prev(it), inf);
    else
        return make_pair(*prev(it), *it);
}

signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int a, b, q;
    cin >> a >> b >> q;
    s.resize(a);
    t.resize(b);
    for (int i = 0; i < a; ++i)
        cin >> s[i];
    sort(s.begin(), s.end());
    for (int i = 0; i < b; ++i)
        cin >> t[i];
    sort(t.begin(), t.end());
    for (int i = 0; i < q; ++i) {
        int64_t x;
        cin >> x;
        pair < int64_t, int64_t > shrine = closest_shrine(x);
        pair < int64_t, int64_t > temple = closest_temple(x);
        int64_t through_temp = min(min(x - closest_shrine(temple.first).first, x - temple.first + closest_shrine(temple.first).second - temple.first),
        min(closest_shrine(temple.second).second - x, temple.second - x + temple.second - closest_shrine(temple.second).first));
        int64_t through_shri = min(min(x - closest_temple(shrine.first).first, x - shrine.first + closest_temple(shrine.first).second - shrine.first),
        min(closest_temple(shrine.second).second - x, shrine.second - x + shrine.second - closest_temple(shrine.second).first));
        cout << min(through_temp, through_shri) << '\n';
    }
}
