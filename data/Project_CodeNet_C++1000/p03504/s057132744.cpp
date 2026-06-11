#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, C, a, b, c;
    cin >> n >> C;
    vector<vector<pair<ll,ll>>> channels(C+1);
    for (ll i=0; i<n; i++) {
        cin >> a >> b >> c;
        channels[c].push_back(make_pair(a,b));
    }
    for (ll i=1; i<=C; i++) sort(channels[i].begin(),channels[i].end());
    vector<ll> cumsum(100001, 0);
    for (ll i=1; i<=C; i++) {
        for (ll j=0; j<channels[i].size(); j++) {
            cumsum[channels[i][j].first-1]++;
            cumsum[channels[i][j].second]--;
            if (j>0 && channels[i][j].first==channels[i][j-1].second) {
                cumsum[channels[i][j].first]++;
                cumsum[channels[i][j].first-1]--;
            }
        }
    }
    ll res = 0;
    ll temp = 0;
    for (auto i : cumsum) {
        temp+=i;
        res = max(res,temp);
    }
    cout << res;
    return 0;
}