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

int ar[102];
lli dp[100005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k;
    cin >> n >> k;

    for(int i=0;i<n;i++)
    {
        cin >> ar[i];
    }

    dp[0] = 1;
    for(int i=0;i<n;i++)
    {
        vector<lli>sum(k+3,0);
        for(int j=k;j>=0;j--)
        {
            int l = j+1;
            int r = j+ar[i];
            r = min(r,k);
            if(l<=r)
            {
                sum[l]+=dp[j];
                sum[r+1]-=dp[j];
            }
        }
        lli pre = 0;
        for(int j=0;j<=k;j++)
        {
            pre += sum[j];
            dp[j] += pre;
            dp[j]+=mod;
            dp[j]%=mod;
        }
    }
    cout << dp[k] << endl;
    return 0;

}

