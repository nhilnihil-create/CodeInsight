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
lli dp[22][2097155];
int n;

lli func(int i,int mask)
{
    if(i==n)
    {
        if(1<<n == mask+1)
            return 1;
        else return 0;
    }
    if(dp[i][mask]!=-1)
        return dp[i][mask];
    lli ret = 0;
    for(int j=0;j<n;j++)
    {
        if(ar[i][j] && !(mask & (1<<j)))
        {
            ret += func(i+1,mask|(1<<j));
            ret %= mod;
        }
    }
    return dp[i][mask] = ret;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    cin >> n;

    mem(dp,-1);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> ar[i][j];
        }
    }

    lli ans = func(0,0);
    cout << ans << endl;
    return 0;

}

