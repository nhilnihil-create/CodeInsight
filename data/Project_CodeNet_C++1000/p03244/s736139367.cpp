//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using ld = long double;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;

bool comp(P x, P y) {
    return x.second < y.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vi v(n);
    bool same = true;
    rep(i, n) {
        cin >> v[i];
        if(v[0] != v[i]) same = false;
    }

    if(same) {
        cout << n/2 << endl;
        return 0;
    }

    map<int, int> od, ev;
    rep(i, n) {
        if(i&1) {
            od[v[i]]++;
        } else {
            ev[v[i]]++;
        }
    }

    vector<P> odp, evp;
    for(P x:od) {
        odp.emplace_back(x);
    }
    for(P x:ev) {
        evp.emplace_back(x);
    }

    sort(rall(odp), comp);
    sort(rall(evp), comp);

    int ans = INT_MAX;
    rep(i, min((int)odp.size(), 2)) {
        rep(j, min((int)evp.size(), 2)) {
            if(odp[i].first == evp[j].first) continue;
            ans = min(ans, n-odp[i].second-evp[j].second);
        }
    }

    cout << ans << endl;
}