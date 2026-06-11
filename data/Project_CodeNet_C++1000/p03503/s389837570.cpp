#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int N;
    cin >> N;

    vector<vector<ll>> F(N, vector<ll>(10));
    vector<vector<ll>> P(N, vector<ll>(11));

    rep(i, N) rep(j, 10) cin >> F.at(i).at(j);
    rep(i, N) rep(j, 11) cin >> P.at(i).at(j);

    ll ans = -10e9;
    for (ll i = 1; i < (1 << 10); i++)
    {
        ll tmp = i;
        vector<ll> C(N, 0);

        ll cnt = 0;
        while (tmp > 0)
        {
            if (tmp % 2 == 1)
            {
                for (ll j = 0; j < N; j++)
                {
                    if (F.at(j).at(cnt) == 1)
                    {
                        C.at(j)++;
                    }
                }
            }
            tmp /= 2;
            cnt++;
        }

        ll sum = 0;
        rep(j, N)
        {
            sum += P.at(j).at(C.at(j));
        }
        ans = max(ans, sum);
    }

    cout << ans << endl;
    return 0;
}