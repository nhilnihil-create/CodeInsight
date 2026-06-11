#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int d; cin >> d;
    ll g; cin >> g;
    g/=100;
    vector<pair<ll, ll>> info(d);
    for (int i=0; i<d; ++i) {
        cin >> info[i].first >> info[i].second;
    }
    ll ans=1e9;
    for (ll i=0; i<(1<<d); ++i) {
        ll cur=0;
        ll c=0;
        ll largest_unsolved=0;
        for (ll k=0; k<d; ++k) {
            if ((i>>k)&1) {
                cur+=(k+1)*info[k].first+info[k].second/100;
                c+=info[k].first;
            } else {
                largest_unsolved=k+1;
            }
        }
        ll rest=g-cur;
        if (rest<=0) {
            ans=min(ans, c);
            continue;
        }
        ll cnt=(rest+largest_unsolved-1)/largest_unsolved;
        if (cnt<info[largest_unsolved-1].first) {
            c+=cnt;
            ans=min(ans, c);
        }
    }
    cout << ans;
    return 0;
}