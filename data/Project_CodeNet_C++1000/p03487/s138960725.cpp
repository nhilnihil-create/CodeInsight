#include <bits/stdc++.h>
typedef long long ll;

#define rep(i, a, n) for (ll i = a; i < (ll)n; ++i)
#define INF 10e12
#define MOD 1000000000 + 7
#define MAX 51000
#define all(x) (x).begin(), (x).end()
#define MX(x) *max_element(all(x))
#define MN(x) *min_element(all(x))

using namespace std;
int main(void)
{
    int n;
    cin >> n;
    vector<ll> v(n);
    map<ll, ll> mp;
    rep(i, 0, n) cin >> v[i], mp[v[i]]++;
    ll ans = 0;
    for (auto i : mp)
    {
        if (i.first > i.second)
            ans += i.second;
        else if (i.first == i.second)
            continue;
        else
            ans += i.second - i.first;
    }
    cout << ans << endl;
}
