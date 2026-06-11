#include <iostream>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<long long int,long long int>,null_type,less<pair<long long int,long long int> >,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

void go()
{
    ll int n,m,mod=(ll int)1e9+7;
    cin>>n>>m;
    vector<vector<char> > a(n,vector<char>(m));
    vector<vector<ll int> > dp(n,vector<ll int>(m,0)),temp(n,vector<ll int>(m,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
            if(a[i][j] == '.')
                temp[i][j]=1;
        }
    }
    dp[0][0]=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i > 0 && j > 0)
            {
                if(a[i][j]=='.')
                    dp[i][j]=dp[i-1][j]+dp[i][j-1],dp[i][j]%=mod;
                else
                    dp[i][j]=0;
            }
            if(i == 0 && j > 0)
            {
                if(a[i][j]=='.')
                    dp[i][j]=dp[i][j-1],dp[i][j]%=mod;
                else
                    dp[i][j]=0;
            }
            if(i > 0 && j == 0)
            {
                if(a[i][j]=='.')
                    dp[i][j]=dp[i-1][j],dp[i][j]%=mod;
                else
                    dp[i][j]=0;
            }
            //cout<<dp[i][j]<<" ";
        }
        //cout<<endl;
    }
    cout<<dp[n-1][m-1];
}
int main()
{
    FIO;
//    int t;
//    cin>>t;
//    while(t--)
        go();
    return 0;
}

