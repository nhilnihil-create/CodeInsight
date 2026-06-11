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

int ar[22][22];
lli dp[2097155];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int n;
    cin >> n;


    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> ar[i][j];
        }
    }

    dp[0] = 1;
    for(int mask=0; mask<(1<<n)-1; mask++)
    {
        int a = __builtin_popcount(mask);

        for(int i=0;i<n;i++)
        {
            if(ar[a][i] && !(mask & (1<<i)))
            {
                int mask2 = mask|(1<<i);
                dp[mask2] += dp[mask];
                dp[mask2] %= mod;
            }
        }
    }
    cout << dp[(1<<n)-1] << endl;
    return 0;

}

