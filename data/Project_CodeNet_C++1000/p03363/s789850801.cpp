#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()
#define all2(a, b) (a).begin(), (a).begin() + (b)
#define debug(vari) cerr << #vari << " = " << (vari) << endl;

const int INF = 1001001001;

int ck(int a)
{
    if (a == 1)
    {
        return 0;
    }
    for (int i = 2; i * i <= a; i++)
    {
        if (a % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int n;
    cin >> n;
    vector<ll> su(n), cum(n + 1, 0);
    rep(i, n) cin >> su[i];
    rep(i, n) cum[i + 1] += su[i] + cum[i];

    map<ll, ll> mp;
    rep(i, n + 1)
    {
        mp[cum[i]]++;
    }

    ll ans = 0;
    for (auto itr : mp)
    {
        ll n = itr.second;
        ans += n * (n - 1) / 2;
    }

    cout << ans << endl;

    return 0;
}