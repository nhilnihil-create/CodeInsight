#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main () {
    ll N, K;
    cin >> N >> K;
    vector<ll> a(N+1, 0);
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
        a[i] += a[i-1];
    }
    set<ll> s;
    for (int l = 1; l <= N; l++) {
        for (int r = l; r <= N; r++) {
            s.insert(a[r]-a[l-1]);
        }
    }
    ll ans = 0;
    for (int k = 60; k >= 0; k--) {
        int c = 0;
        set<ll> ss = s;
        for (auto i = ss.begin(); i != ss.end();) {
            if ((1LL << k) & (*i)) {
                i++;
            }
            else {
                ss.erase(i++);
            }
        }
        if (ss.size() >= K) {
            s = ss;
            ans += (1LL << k);
        }
    }
    cout << ans << endl;
}