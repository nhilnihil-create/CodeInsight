#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 

ll dest;
int matrix[22][22];
ll mod = 1000000007;
ll dp[22][(1<<22)];

ll go(int man,ll mask,int n)
{
    if(man == n+1)
    {
        if(mask == 0)
            return 1;
        return 0;
    }
    
    if(dp[man][mask] != -1)
        return dp[man][mask];
    
    ll ans = 0;
    
    for(int woman=0;woman<n;woman++)
    {
        bool avail = (((1<<(woman))&mask) == 0) ? 0 : 1;
        if(avail == 1 && matrix[man][woman+1] == 1)
        {
            ans = (ans + (go(man+1,mask ^ (1<<woman),n))%mod)%mod;
        }
    }
    
    return dp[man][mask] = ans;
}

int main()
{
    int n;
    cin >> n;
    
    dest = (1<<n)-1;

    memset(dp,-1,sizeof(dp));
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin >> matrix[i][j];
        }
    }
    
    cout << go(1,dest,n) << endl;
    return 0;
}