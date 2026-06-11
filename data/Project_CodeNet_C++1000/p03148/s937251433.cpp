#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main () {
    ll N, K;
    cin >> N >> K;
    vector<pair<ll, int>> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i].second >> v[i].first;
    }
    sort(v.begin(), v.end(), [](auto x, auto y) {
        return x.first > y.first;
    });
    ll ans = 0;
    set<int> s;
    ll r = 0;
    set<pair<ll, int>> t;
    for (int i = 0; i < K; i++) {
        if (s.find(v[i].second) != s.end()) {
            t.insert(make_pair(v[i].first, i));
        }
        else {
            s.insert(v[i].second);
        }
        r += v[i].first;
    }
    ans = r + (s.size())*(s.size());
    for (int i = K; i < N; i++) {
        if (t.size() == 0) break;
        if (s.find(v[i].second) == s.end()) {
            r -= (*t.begin()).first;
            t.erase(t.begin());
            r += v[i].first;
            s.insert(v[i].second);
            ans = max(ans, r+(ll)s.size()*(ll)s.size());
        }
    }
    cout << ans << endl;
}