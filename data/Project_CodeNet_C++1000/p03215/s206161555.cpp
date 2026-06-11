#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int N, K;
    cin >> N >> K;
    vector<ll> a(N), sum(N+1, 0);
    vector<ll> b;
    for (int i = 0; i < N; i++) cin >> a[i];
    for (int i = 0; i < N; i++) sum[i+1] = sum[i] + a[i];
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < i; j++) {
            b.push_back(sum[i]-sum[j]);
        }
    }
    sort(b.begin(), b.end());
    ll ans = 0;
    for (int i = 50; i >= 0; i--) {
        ll cand = ans + ((ll)1 << i);
        int cnt = 0;
        for (ll x : b) {
            if ((cand&x)==cand) cnt++;
        }
        if (cnt >= K) ans = cand;
    }
    cout << ans << endl;
    return 0;
}