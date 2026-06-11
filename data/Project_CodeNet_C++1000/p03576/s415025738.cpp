#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define REPV(iter, v) for(auto (iter)=(v).begin(); (iter)!=(v).end();++(iter))
#define ALL(v) (v).begin(),(v).end()

#define MOD 1000000007

using namespace std;

typedef long long ll;

int main()
{
    ll N, K;
    cin >> N >> K;
    vector<ll> x(N), y(N), sortX(N), sortY(N);
    REP(i, N)
    {
        cin >> x[i] >> y[i];
        sortX[i] = x[i];
        sortY[i] = y[i];
    }
    sort(ALL(sortX));
    sort(ALL(sortY));

    ll ans = LONG_MAX;
    for (ll i = 0; i < N - 1; ++i)
    {
        for (ll j = i + 1; j < N; ++j)
        {
            for (ll k = 0; k < N - 1; ++k)
            {
                for (ll l = k + 1; l < N; ++l)
                {
                    ll x1 = sortX[i], x2 = sortX[j], y1 = sortY[k], y2 = sortY[l];
                    // cout << x1 << " " << x2 << " " << y1 << " " << y2 << endl;
                    ll countP = 0;
                    REP(i, N)
                    {
                        if (x[i] >= x1 && x[i] <= x2 && y[i] >= y1 && y[i] <= y2) countP++;
                    }
                    if (countP >= K)
                    {
                        if (x1 < x2 && y1 < y2)
                        {
                            ans = min(ans, (x2 - x1) * (y2 - y1));
                        }
                    }
                }
            }
        }
    }

    cout << ans << endl;
}
