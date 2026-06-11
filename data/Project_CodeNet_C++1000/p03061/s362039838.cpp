#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long int;
int main() {
    ll N;
    cin >> N;

    vector<ll> P(N + 1);
    for (ll i = 0; i < N; i++)
    {
        ll ai;
        cin >> ai;
        P[i + 1] = ai;
    }

    vector<ll> DP1(N + 1);
    vector<ll> DP2(N + 1);
    
    DP1[1] = P[1];
    DP2[N] = P[N];

    for (size_t i = 2; i <= N; i++)
    {
        DP1[i] = __gcd(DP1[i - 1], P[i]);
    }
    for (size_t i = 2; i <= N; i++)
    {
        DP2[N - i + 1] = __gcd(DP2[N - i + 2], P[N - i + 1]);
    }

    ll ans = 0;
    for (size_t i = 1; i <= N; i++)
    {
        if (i == 1) {
            ans = max(ans, DP2[i + 1]);
            continue;
        }
        if (i == N) {
            ans = max(ans, DP1[i - 1]);
        }
        ans = max(ans, __gcd(DP1[i - 1], DP2[i + 1]));
    }
    cout << ans << endl;
}