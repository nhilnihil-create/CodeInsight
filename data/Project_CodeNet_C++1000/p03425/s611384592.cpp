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
    ll n;
    cin >> n;
    vector<string> s(n);
    vector<ll> vmp(5, 0);
    rep(i, 0, n) cin >> s[i];
    rep(i, 0, n)
    {
        if (s[i][0] == 'M')
            vmp[0]++;
        if (s[i][0] == 'A')
            vmp[1]++;
        if (s[i][0] == 'R')
            vmp[2]++;
        if (s[i][0] == 'C')
            vmp[3]++;
        if (s[i][0] == 'H')
            vmp[4]++;
    }
    ll ans = 0;
    rep(i, 0, 3)
    {
        rep(j, i + 1, 4)
        {
            rep(k, j + 1, 5)
            {
                ans += vmp[i] * vmp[j] * vmp[k];
            }
        }
    }
    cout << ans << endl;
}