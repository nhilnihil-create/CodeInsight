/*
    Take me to church
    I'll worship like a dog at the shrine of your lies
    I'll tell you my sins and you can sharpen your knife
    Offer me that deathless death
    Good God, let me give you my life
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 5005;
int n, L, R, A[N];
long long dp[N];
int main()
{
    scanf("%d%d%d", &n, &R, &L);
    for (int i = 1; i <= n; i ++)
        scanf("%d", &A[i]);
    n ++; A[n] = n;
    for (int i = 1; i <= n; i ++)
    {
        int cnt = 0;
        dp[i] = LLONG_MAX;
        for (int j = i - 1; ~ j; j --)
            if (A[j] < A[i])
                dp[i] = min(dp[i], dp[j] + cnt * 1LL * L + (i - j - 1 - cnt) * 1LL * R), cnt ++;
    }
    return !printf("%lld\n", dp[n]);
}