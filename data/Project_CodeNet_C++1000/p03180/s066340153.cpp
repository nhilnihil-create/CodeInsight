#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int N;
int A[16][16];
ll SA[1<<17];
ll dp[1<<17];

int main()
{
    cin >> N;
    for(int y = 0; y < N; y++)
    for(int x = 0; x < N; x++) cin >> A[y][x];
    int mask;
    memset(SA, 0, sizeof(SA));
    for(mask = 0; mask < 1<<N; mask++)
    {
        for(int y = 0; y < N; y++)
        for(int x = y + 1; x < N; x++) 
        if((mask&(1 << y)) && (mask&(1 << x))) SA[mask] += A[y][x];
        dp[mask] = -1LL<<60;
    }
    dp[0] = 0;
    for(mask = 0; mask < 1<<N; mask++)
    {
        int first;
        for(first = 0; first < N; first++) if((mask&(1<<first)) == 0) break;
        int submask =((1<<N)-1)^mask^(1<<first);
        for(int sm2=submask; sm2 >= 0; sm2--)
        {
            sm2 &= submask;
            dp[mask | sm2 | (1<<first)] = max(dp[mask | sm2 | (1<<first)], dp[mask] + SA[sm2 | (1<<first)]);
        }
    }
    cout << dp[(1<<N)-1] <<endl;
}