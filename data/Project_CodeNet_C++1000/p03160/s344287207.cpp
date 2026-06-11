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

int main()
{
    int N;
    cin>>N;
    int a[N];
    for(int i = 0; i < N; i++) cin>>a[i];
    cout << frog1( N, a);
}