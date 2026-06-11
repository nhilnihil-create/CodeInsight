#include<bits/stdc++.h>

using namespace std;

int frog1(int N, int a[])
{
    int dp[N+1];
    dp[0] = 0;
    dp[1] = a[0];
    dp[2] = abs(a[1] - a[0]);
    dp[3] = min(dp[2] + abs(a[2]-a[1]) , abs(a[2]-a[0]));
    for( int i = 3; i < N; i++)
    {
        dp[i+1] = min(dp[i] + abs(a[i]-a[i-1]), dp[i-1] + abs(a[i]-a[i-2]));
    }
    return dp[N];
}

int frog2(int N, int a[], int k)
{
    int dp[N+1];
    dp[0] = 0;
    dp[1] = a[0];
    dp[2] = abs(a[1] - a[0]);
    for( int i = 3; i <= N; i++)
    {
        dp[i] = INT_MAX;
        for(int j = 1 ; j <= k; j++)
            if(i-j-1>=0)
            {
                if(i-j-1 == 0)
                    dp[i] = min(dp[i], abs(a[i-1] - a[i-j-1]));
                else
                    dp[i] = min(dp[i], dp[i-j] + abs(a[i-1]-a[i-j-1]));
            }  
    }

    return dp[N];
}


int main()
{
    int N, k;
    cin>>N>>k;
    int a[N];
    for(int i = 0; i < N; i++) cin>>a[i];
    cout << frog2(N,a,k);
}