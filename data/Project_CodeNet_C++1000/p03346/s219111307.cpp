#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
const ll MAX = 1001001;
const ll MOD = 1000000007;
int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    rep(i, n)
    {
        cin >> a.at(i);
        a[i]--;
        b[a[i]] = i;
    }
    ll now = 0;
    ll ans = 0;
    rep(i, n - 1)
    {
        if (b[i] < b[i + 1])
        {
            now++;
        }
        else
        {
            now = 0;
        }
        ans = max(ans, now);
    }
    ans = max(ans, now);
    cout << n - 1 - ans << endl;
}
