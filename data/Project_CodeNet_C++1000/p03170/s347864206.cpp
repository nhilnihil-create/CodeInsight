#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define F first
#define S second
#define ii pair < int , int >
#define ever (;;)

const int N = 110;

int n,k,a[N],dp[100100];

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);

    for(int i=1;i<=k;i++)
        for(int j=1;j<=n;j++)
            if( i-a[j] >= 0 )
                dp[i] |= !dp[i-a[j]];

    printf( ( dp[k] ) ? "First\n" : "Second\n" );
}
