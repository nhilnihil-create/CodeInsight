#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll N, K;
    cin >> N >> K;
    vector<ll> h(N);
    for (ll i = 0; i < N; ++i)
    {
        cin >> h[i];
    }
    sort(h.begin(), h.end());
    ll ans = 1000000000;
    for (ll i = 0; i < N - K + 1; ++i)
    {
        ans = min(ans, h[i + K - 1] - h[i]);
    }
    cout << ans << endl;
}
