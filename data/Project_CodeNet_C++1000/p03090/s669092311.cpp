#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
const ll MAX = 1001001;
const ll MOD = 1000000007;
const ll INF = 1001001001;

int main()
{
    ll n;
    cin >> n;
    vector<P> a;
    if (n % 2 != 0)
    {
        rep2(i, 1, n + 1)
        {
            rep2(j, 1, n + 1)
            {
                if (i != j && i != n - j)
                {
                    if (i < j)
                    {
                        a.emplace_back(i, j);
                    }
                }
            }
        }
        cout << a.size() << endl;
        rep(i, a.size())
        {
            cout << a[i].first << " " << a[i].second << endl;
        }
        return 0;
    }
    rep2(i, 1, n + 1)
    {
        rep2(j, 1, n + 1)
        {
            if (i != j && i != n + 1 - j)
            {
                if (i < j)
                {
                    a.emplace_back(i, j);
                }
            }
        }
    }
    cout << a.size() << endl;
    rep(i, a.size())
    {
        cout << a[i].first << " " << a[i].second << endl;
    }
}