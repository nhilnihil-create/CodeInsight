#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, K; cin >> N >> K;
    vector<ll> a(N); for (int i = 0; i < N; i++) cin >> a[i];
    vector<ll> cum(N); cum[0] = a[0];
    for (int i = 1; i < N; i++) cum[i] = cum[i-1] + a[i];
    map<ll, int> pr;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            if (i == 0) pr[cum[j]]++;
            else pr[cum[j] - cum[i-1]]++;
        }
    }
    for (int i = 62; 0 <= i; i--) {
        map<ll, int> tmp;
        int t = 0;
        for (auto x : pr) {
            if (x.first>>i & 1) {
                t += x.second;
                tmp[x.first] = x.second;
            }
        }
        if (t >= K) pr = tmp;
    }
    ll ans = (ll)1<<60;
    ans -= 1;
    for (auto x : pr) {
        ans &= x.first;
    }
    cout << ans << endl;
}