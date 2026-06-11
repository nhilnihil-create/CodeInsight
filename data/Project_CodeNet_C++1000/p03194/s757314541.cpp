#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

const ll INF = 1LL << 60;

ll N, K;
int main() {
    cin >> N >> K;
    map<ll, ll> mp;
    for (ll i = 2; i * i <= K; i++) {
        if (K % i == 0) {
            ll cnt = 0;
            while (K % i == 0) {
                K /= i;
                cnt++;
            }
            mp[i] = cnt;
        }
    }
    if (K != 1) mp[K] = 1;

    ll ans = 1;
    for (auto iter = mp.begin(); iter != mp.end(); iter++) {
        // cout << iter->first << " " << iter->second << endl;
        ll sisuu = iter->second / N;
        ans *= pow(iter->first, sisuu);
    }
    cout << ans << endl;
}