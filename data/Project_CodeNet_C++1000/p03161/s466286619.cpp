#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N,K;
    cin >> N >> K;
    int j[N],dp[N];
    for(int i=0;i<N;i++)
    {
        cin >> j[i];
    }
    memset(dp,1000000,sizeof(dp));

    dp[0]=0;
    // dp[1]=abs(j[1]-j[0]);
    // int ind,val;
    for(int i=1;i<N;i++)
    {
        for(int r = 1; r<=min(i,K);r++)
        {
            dp[i] = min(dp[i-r] + abs(j[i] - j[i-r]), dp[i]);
        }
    }

    cout << dp[N-1] << endl;
    
    return 0;
}