#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define REPV(iter, v) for(auto (iter)=(v).begin(); (iter)!=(v).end();++(iter))
#define ALL(v) (v).begin(),(v).end()

#define MOD 1000000007

using namespace std;

typedef long long ll;

int main()
{
    ll D, G;
    cin >> D >> G;
    vector<ll> p(D), c(D);
    REP(i, D)
    {
        cin >> p[i] >> c[i];
    }

    ll ans = LONG_MAX;
    for (int i = 0; i < (1 << D); i++)
    {
        ll score = 0;
        ll count = 0;
        ll maxNum = -1;
        REP(j, D)
        {
            if ((i >> j) & 1)
            {
                score += 100 * (j + 1) * p[j];
                score += c[j];
                count += p[j];
            }
            else
            {
                maxNum = max(maxNum, (ll)j);
            }
        }
        if (G - score > 0)
        {
            if (maxNum != -1 && (100 * (maxNum + 1)) * (p[maxNum] - 1) >= G - score)
            {
                count += (G - score) > 100 * (maxNum + 1) ? (G - score) / (100 * (maxNum + 1)) : 1;
            }
            else
            {
                continue;
            }
        }
        ans = min(ans, count);
    }

    cout << ans << endl;
}
