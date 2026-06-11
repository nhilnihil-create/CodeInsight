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
    ll n, a, b;
    cin >> n >> a >> b;
    vector<ll> p(n);
    ll x = 0;
    ll y = 0;
    ll z = 0;
    rep(i, n)
    {
        cin >> p[i];
        if (p[i] <= a)
        {
            x++;
        }
        else if (p[i] > b)
        {
            z++;
        }
        else
        {
            y++;
        }
    }

    cout << min({x, y, z}) << endl;
}