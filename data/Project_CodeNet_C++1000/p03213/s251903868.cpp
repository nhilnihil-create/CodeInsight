#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < n; i++)
#define repr(i, n) for(ll i = n; i >= 0; i--)
#define reprr(i, m, n) for (ll i = m; i < n; i++)
#define inf 2e9
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

map<ll, ll> mp;

void prime_factorize(ll n) {
    while (n % 2 == 0) mp[2]++, n /= 2;

    for (ll i = 3; i <= sqrt(n); i+=2) {
        while (n % i == 0) mp[i]++, n /= i;
    }

    if (n > 2) mp[n]++;
}

int main()
{
    ll N; cin >> N;
    for (ll i = 1; i <= N; i++) {
        prime_factorize(i);
    }

    ll o75 = 0, o25 = 0, o15 = 0, o5 = 0, o3 = 0;
    for (auto p : mp) {
        if (p.second + 1 >= 75) o75++;
        if (p.second + 1 >= 25) o25++;
        if (p.second + 1 >= 15) o15++;
        if (p.second + 1 >=  5)  o5++;
        if (p.second + 1 >=  3)  o3++;
    }

    ll ans = 0;
    ans += o75;
    ans += o25 * (o3 - 1);
    ans += o15 * (o5 - 1);
    ans += (o5 * (o5 - 1) / 2) * (o3 - 2);
    cout << ans << endl;
    return 0;
}