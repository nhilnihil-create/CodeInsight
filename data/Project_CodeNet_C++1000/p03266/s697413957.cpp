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
    for (int i = 1; i <= N; ++i)
    {
        if ((2 * i) % K == 0)
        {
            int res = i % K;
            ll count = N / K;
            if (N - K * (N / K) >= K - res) count++;
            ans += count * count;
        }
    }

    cout << ans << endl;
}
