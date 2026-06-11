#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define F first
#define S second
#define ii pair < int , int >
#define ever (;;)

const int N = 100100;

int n,a[N],dp[N],k;

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);

    for(int i=n-1;i>=1;i--)
    {
        dp[i] = 2e9;

        for(int j=i+1;j<=min(i+k,n);j++)
            dp[i] = min( dp[i] , abs(a[i]-a[j]) + dp[j] );
    }

    printf("%d\n",dp[1]);
}
