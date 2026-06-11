/**
*    author:  yuya1234
*    created: 25.06.2020 15:29:56
**/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
#define REPD(i, n) for (ll i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (ll i = a; i <= (ll)(b); i++)
#define FORD(i, a, b) for (ll i = a; i >= (ll)(b); i--)

#define SORT(s) sort((s).begin(), (s).end())
#define SORTD(s) sort((s).rbegin(), (s).rend())
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end());

#define SZ(x) ((int)(x).size())
#define MEMSET(v, h) memset((v), h, sizeof(v))

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    int tmp, ans = 0;
    map<int, int> m;
    vector<int> v;

    REP(i, n)
    {
        cin >> tmp;
        ans++;
        if (m.count(tmp) == 0)
            m.insert(make_pair(tmp, 1));
        else
            m[tmp]++;
    }

    for (auto it = m.begin(); it != m.end(); ++it)
    {
        v.push_back(it->second);
    }
    SORTD(v);

    int aa;
    int i = 0;

    REP(j, k)
    {
        for (auto it = m.begin(); it != m.end(); ++it)
        {
            if (it->second == v[i])
            {
                ans -= it->second;
                m.erase(it->first);
                break;
            }
        }
        i++;
    }

    cout << ans << endl;

    return 0;
}