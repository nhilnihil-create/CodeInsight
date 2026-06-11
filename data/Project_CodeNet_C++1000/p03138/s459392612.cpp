#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, K;
vector<ll> A;
ll v[60], vv[60];
int main () {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        A.push_back(a);
        for (int j = 0; j < 60; j++) {
            if ((1LL << j) & a) {
                v[j]++;
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < 60; i++) {
        vv[i] = max(v[i], N-v[i])*(1LL << i);
        if (i) {
            vv[i] += vv[i-1];
        }
        if ((1LL << i) & K) {
            ans += (N-v[i])*(1LL << i);
        }
        else {
            ans += v[i]*(1LL << i);
        }
    }
    ll res = 0;
    for (int i = 59; i >= 0; i--) {
        if ((1LL << i) & K) {
            ans = max(ans, res+v[i]*(1LL << i)+((i > 0)?vv[i-1]:0));
            res += (N-v[i])*(1LL << i);
        }
        else {
            res += v[i]*(1LL << i);
        }
    }
    cout << ans << endl;
}