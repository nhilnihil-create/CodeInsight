#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e5 + 1;
const int MOD = 1e9 + 7;

int dp[MAX];

void add_self(int &a, int b)
{
    a += b;

    if(a >= MOD)
        a %= MOD;
}

void sub_self(int &a, int b)
{
    a -= b;

    if(a < 0)
        a += MOD;
}

int main()
{
    int n, k;

    cin >> n >> k;

    dp[0] = 1;
    for(int child = 1; child <= n; ++child)
    {
        int nrCandies;

        cin >> nrCandies;

        vector<int> aux(k + 1);
        for(int used = k; used >= 0; used--)
        {
            int temp = dp[used];
            int L = used + 1;
            int R = used + min(nrCandies, k - used);

            if(L <= R)
            {
                add_self(aux[L], temp);

                if(R + 1 <= k)
                    sub_self(aux[R + 1], temp);
            }
        }

        int prefixSum = 0;
        for(int i = 0; i <= k; i++)
        {
            prefixSum = (prefixSum + aux[i]) % MOD;
            dp[i] = (dp[i] + prefixSum) % MOD;
        }
    }

    cout << dp[k];

    return 0;
}
