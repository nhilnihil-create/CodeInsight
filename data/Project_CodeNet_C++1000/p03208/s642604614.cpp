#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
//cout << setprecision(20) << 
const ll INF = 1e18;

int main() {
    ll N, K; cin >> N >> K;
    vector<ll> v(N);
    for (int i = 0; i < N; ++i) cin >> v[i];
    sort(v.begin(), v.end());

    ll min_height = INF;
    for (int i = 0; i + K - 1 < N; ++i) {
        min_height = min(min_height, v[i + K - 1] - v[i]);
    }
    cout << min_height << endl;
}