#include <bits/stdc++.h>
#define ll long long
using namespace std;

int dp[100005], a[100005];
int n;

int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>a[i];

    dp[1]=0;
    for(int i=2; i<=n; i++)
    {
        dp[i]=dp[i-1] + abs(a[i]-a[i-1]);
        if(i>2)
            dp[i]=min(dp[i], dp[i-2] + abs(a[i]-a[i-2]));
    }
    cout<< dp[n] <<endl;
}

