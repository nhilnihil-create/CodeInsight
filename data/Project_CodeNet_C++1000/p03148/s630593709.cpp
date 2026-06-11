#include<bits/stdc++.h>

using namespace std;
using ll = long long int;

int main(void) {
    constexpr ll MOD = 1e9 + 7;
    cout << fixed << setprecision(16);

    ll n, k;
    cin >> n >> k;
    vector<pair<ll,ll>> v(n);
    for(auto &e: v)
        cin >> e.second >> e.first;
    sort(v.begin(), v.end(), greater<>());

    ll kiso = 0;
    map<ll,ll> cnt;
    for(ll i=0; i<k; i++)
        kiso += v[i].first, cnt[v[i].second]++;
    ll kind = cnt.size();

    ll res = kiso + kind*kind;

    ll i = k, j = k-1;
    while(1) {
        while(i<n && cnt.count(v[i].second)) i++;
        if(i>=n) break;
        while(j>=0 && cnt[v[j].second]<=1) j--;
        if(j<0) break;

        kiso += v[i].first - v[j].first;
        kind++;
        res = max(res, kiso + kind*kind);
        cnt[v[j].second]--;
        cnt[v[i].second]++;
        i++, j--;
    }
    cout << res << endl;
}
