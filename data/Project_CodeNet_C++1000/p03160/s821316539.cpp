#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define F first
#define S second
#define ii pair < int , int >
#define ever (;;)

const int N = 100100;

int n,a[N],dp[N];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);

    dp[n+1] = 2e9;

    for(int i=n-1;i>=1;i--)
        dp[i] = min( abs(a[i]-a[i+1]) + dp[i+1] , abs(a[i]-a[i+2]) + dp[i+2] );

    printf("%d\n",dp[1]);
}
