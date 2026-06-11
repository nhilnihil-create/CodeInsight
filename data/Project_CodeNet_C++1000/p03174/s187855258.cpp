#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define INF 99999999
const long int M = 1000000007;

int allmask;
map<int,vector<int> > m;
int dp[(1<<21) + 1];
lli solve(int mask, int i, int n)
{
    if(mask == allmask) return 1;
    if(i > n) return 0;
    if(dp[mask] != -1) return dp[mask];
    lli ways = 0;
    int si = m[i].size();
    for(int j = 0;j < si;j++)
    {
        if(mask & (1 << m[i][j])) continue;
        else ways += solve(mask |(1<<m[i][j]),i+1,n);
        ways %= M;
    }
    return dp[mask] = ways;
}

int main()
{
    int n;
    cin >> n;
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            int a;
            cin >> a;
            if(a)
            {
                m[i+1].push_back(j);
            }
        }
    }
    allmask = (1 << n) - 1;
    memset(dp,-1,sizeof(dp));
    cout << solve(0,1,n);
    /*for(i=1;i<=3;i++)
    {
        cout << i<< ": ";
        for(j=0;j<m[i].size();j++)
        {
            cout  << m[i][j] << ",";
        }
        cout << endl;
    }*/
    /*cout << endl;
    for(i=0;i<(1<<n);i++)
    {
        //for(j=0;j<n;j++)
        {
            cout << dp[i] << "\t";
        }
        cout << endl;
    }*/
}

