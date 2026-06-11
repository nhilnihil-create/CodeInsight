#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
typedef pair<ll, ll> p;

#define MOD 1000000007

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, K;
    cin >> N >> K;

    vector<p> v(N);

    for(ll i = 0; i < N; i++) {
        ll t, d;
        cin >> t >> d;
        v[i] = make_pair(d, t);
    }

    sort(v.begin(), v.end(), greater<p>());

    ll c = 0;
    ll k = 0;

    vector<ll> b(N + 10);

    for(ll i = 0; i < K; i++) {
        ll t = v[i].second;
        ll d = v[i].first;
        if(!b[t]) {
            k++;
        }
        b[t]++;
        c += d;
    }

    ll ans = c + k * k;

    ll pos = K - 1LL;

    for(ll i = K; i < N; i++) {
        ll t = v[i].second;
        ll d = v[i].first;
        if(b[t]) continue;
        while(true) {
            ll pt = v[pos].second;
            ll pd = v[pos].first;
            if(b[pt] > 1) {
                b[pt]--;
                b[t]++;
                k++;
                c -= pd;
                c += d;
                ans = max(ans, c + k * k);
            }
            pos--;
            if(pos < 0) {
                cout << ans << endl;
                return 0;
            }
            if(b[t]) break;
        }
    }

    cout << ans << endl;
}