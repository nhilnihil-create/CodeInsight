#include<bits/stdc++.h>
#define sf1(n) scanf("%d",&n)
#define sf2(n,q) scanf("%d %d",&n,&q)
#define f first
#define ss second
#define pb push_back
#define lli long long
#define mem(ar,false) memset(ar,false,sizeof(ar))
#define mpr make_pair
#define endl "\n"
#define mod 1000000007
#define inf 9000000000000000000LL
using namespace std;

int ar[502];
lli dp[505][505];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for(int i =1; i<=n; i++)
    {
        cin >> ar[i];
    }

    for(int i=n; i>=1; i--)
    {
        for(int j=i; j<=n; j++)
        {
            if(j==i)
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = inf;
                lli sum = 0;
                for(int k=i; k<=j; k++)
                    sum+=ar[k];
                for(int k=i; k<=j-1; k++)
                {
                    dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]+sum);
                }
            }
        }
    }
    cout << dp[1][n] <<endl;
    return 0;

}

