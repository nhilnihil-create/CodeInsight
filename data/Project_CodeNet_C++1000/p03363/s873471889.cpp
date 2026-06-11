#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;
    vector<ll> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    vector<ll> a_accum(N+1, 0);
    for (int i = 0; i < N; i++) {
        a_accum[i+1] = (a_accum[i] + a[i]);
    }
    map<ll, ll> m;
    for (auto s : a_accum) {
        m[s]++;
    }
    m[0LL] --;
    ll ans = m[0LL];
    for (auto t : m) {
        ans += (t.second*(t.second-1LL)/2LL);
    }
    cout << ans << endl;
}