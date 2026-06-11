#include <bits/stdc++.h>
#define INF 5000000000000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

int main()
{
    ll mod = 1000000007;
    ll N;
    cin >> N;
    string S;
    cin >> S;
    vector<ll> alfa(26, 0);
    for (ll i = 0; i < N; ++i)
    {
        alfa.at(S.at(i) - 'a') += 1;
    }
    ll ans = 1;
    for (ll i = 0; i < 26; ++i)
    {
        ans = ans * (alfa.at(i) + 1) % mod;
    }
    ans -= 1;
    if (ans < 0)
    {
        ans += mod;
    }
    cout << ans << endl;
}
