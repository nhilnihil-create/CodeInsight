#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    int N, d;
    cin >> N;
    vector<int> nd(13);
    nd[0]++;
    for ( int i = 0; i < N; i++ ) {
        cin >> d;
        nd[d]++;
    }
    for ( int i = 1; i < 12; i++ ) {
        if ( nd[i] > 2 ) return 0;
    }
    if ( nd[0] > 1 ) return 0;
    if ( nd[12] > 1 ) return 0;
    vector<int> d1, d2, d0;
    if ( nd[12] > 0 ) d0.push_back(12);
    for ( int i = 1; i < 12; i++ ) {
        if ( nd[i] == 1 ) d1.push_back(i);
        else if ( nd[i] == 2 ) d2.push_back(i);
    }

    ll ans = 0;
    for ( int k = 0; k < (1<<d1.size()) ; k++ ) {
        vector<int> d;
        d.push_back(0);
        d.push_back(24);
        for ( int j = 0; j < d0.size(); j++ ) {
            d.push_back(d0[j]);
        }
        for ( int j = 0; j < d2.size(); j++ ) {
            d.push_back(d2[j]);
            d.push_back(24-d2[j]);
        }
        for ( int i = 0; i < d1.size(); i++ ) {
            if ( (k>>i) & 1 ) d.push_back(d1[i]);
            else d.push_back(24-d1[i]);
        }
        sort(d.begin(), d.end());
        int mn = 24;
        for ( int i = 1; i < d.size(); i++ ) {
            int diff = d[i] - d[i-1];
            if ( mn > diff ) mn = diff;
        }
        if ( ans < mn ) ans = mn;
    }
    return ans;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}