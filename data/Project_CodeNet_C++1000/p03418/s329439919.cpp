#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define MOD 1000000007

using namespace std;

typedef long long ll;

int main()
{
    ll N, K;
    cin >> N >> K;
    ll ans = 0;
    if (K == 0)
    {
        ans = N * N;
    }
    else
    {
        for (ll b = K + 1; b <= N; ++b)
        {
            ans += (N / b) * (b - K);
            ll res = N % b;
            if (res >= K)
            {
                ans += res + 1 - K;
            }
        }
    }

    cout << ans << endl;
}
