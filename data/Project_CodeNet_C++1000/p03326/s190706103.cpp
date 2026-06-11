#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define MOD 1000000007

int main(void) {
    ll N, M;
    ll ans = LONG_LONG_MIN;
    vector<tuple<ll, ll, ll>> S;
    cin >> N >> M;
    S.resize(N);
    for(ll i = 0;i < N;i++) cin >> get<0>(S[i]) >> get<1>(S[i]) >> get<2>(S[i]);
    for(ll i = 0;i < 8;i++) {
        ll a = 0;
        vector<ll> s;
        for(ll j = 0;j < N;j++) {
            ll t = 0;
            t += ((i & 1) ? 1 : -1) * get<0>(S[j]);
            t += ((i & 2) ? 1 : -1) * get<1>(S[j]);
            t += ((i & 4) ? 1 : -1) * get<2>(S[j]);
            s.push_back(t);
        }
        sort(s.begin(), s.end(), greater<>());
        for(ll j = 0;j < M;j++) a += s[j];
        ans = max(ans, a);
    }
    cout << ans << endl;
    return 0;
}
