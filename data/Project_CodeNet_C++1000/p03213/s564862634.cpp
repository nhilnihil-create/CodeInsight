#include <iostream>
#include <vector>
#include <map>

using namespace std;
typedef long long ll;

int main() {
    ll n;   cin >> n;
    
    vector<ll> c(101);
    for (int i = 0; i <= 100; i++)
        c[i] = i;

    for (ll i = 2; i * i <= 100; i++) {
        if (c[i] != i)
            continue;

        for (ll j = i; j * i <= 100; j++) {
            c[j*i] = i;
        }
    }

    map<ll, ll> mp;
    for (int i = 1; i <= n; i++) {
        ll x = i;
        while (x != 1) {
            mp[c[x]]++;
            x /= c[x];
        }
    }
    

    vector<ll> cnt(76, 0);
    for (auto p: mp) {
        ll tmp = p.second;
        if (2 <= tmp)
            cnt[2]++;
        if (4 <= tmp)
            cnt[4]++;
        if (14 <= tmp)
            cnt[14]++;
        if (24 <= tmp)
            cnt[24]++;
        if (74 <= tmp)
            cnt[74]++;
    }
    ll ans = 0;
    ans += (cnt[2]-cnt[4]) * cnt[4] * (cnt[4]-1) / 2;
    ans += cnt[4] * (cnt[4]-1) * (cnt[4]-2) / 2;
    ans += cnt[14] * (cnt[14]-1);
    ans += cnt[14] * (cnt[4] - cnt[14]);
    ans += cnt[24] * (cnt[24] - 1) ;
    ans += cnt[24] * (cnt[2] - cnt[24]);
    ans += cnt[74];
    cout << ans << endl;
    return 0;
}