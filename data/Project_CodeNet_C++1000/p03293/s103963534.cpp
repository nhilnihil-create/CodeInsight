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
    string s, t;
    cin >> s >> t;
    ll n = s.size();
    rep(i, n)
    {
        if (s.substr(0, i) == t.substr(n - i, i))
        {
            if (s.substr(i, n - i) == t.substr(0, n - i))
            {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}