#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353

int main() {
    int N, K; cin >> N >> K;
    vector<ll> h(N);
    for (int i = 0; i < N; i++) {
        cin >> h.at(i);
    }
    sort(h.begin(), h.end());
    ll ans = inf;
    for (int i = 0; i < N - K + 1; i++) {
        ll dist = h.at(i + K - 1) - h.at(i);
        ans = min(ans, dist);
    }
    cout << ans << endl;
    return 0;
}