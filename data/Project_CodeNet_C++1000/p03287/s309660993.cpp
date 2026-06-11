#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, M; cin >> N >> M;
    vector<ll> A(N); for (int i = 0; i < N; i++) cin >> A[i];
    vector<ll> cum(N); cum[0] = A[0] % M;
    for (int i = 1; i < N; i++) cum[i] = (cum[i-1] + A[i]) % M;
    map<ll, ll> group;
    group[0]++;
    for (int i = 0; i < N; i++) {
        group[cum[i]]++;
    }
    ll ans = 0;
    for (auto x : group) {
        ans += x.second * (x.second - 1) / 2;
    }
    cout << ans << endl;
}
