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
    string a,b,ans="";
    cin>>a>>b;
    int curr=0;
    int n=a.size();
    int m=b.size();
    vector<vector<int> > dp(n,vector<int>(m,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i == 0 && j == 0)
            {
                if(a[i] == b[j])
                    dp[i][j]=1;
            }
            else if(i == 0 && j>0)
            {
                if(a[i] == b[j])
                    dp[i][j]=1;
                else
                    dp[i][j]=dp[i][j-1];
            }
            else if(j == 0 && i>0)
            {
                if(a[i] == b[j])
                    dp[i][j]=1;
                else
                    dp[i][j]=dp[i-1][j];
            }
            else
            {
                if(a[i] == b[j])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
            //cout<<dp[i][j]<<" ";
        }
        //cout<<endl;
    }
    int i=n-1,j=m-1;
    while(i>0 && j>0)
    {
        if(a[i] == b[j])
            ans+=a[i],i--,j--;
        else
        {
            if(dp[i-1][j] >= dp[i][j-1])
                i--;
            else
                j--;
        }
    }
    //cout<<ans<<endl;
    if(i == 0)
    {
        while(j>=0)
        {
            if( a[i] == b[j] )
            {
                ans+=a[i];
                break;
            }
            j--;
        }
    }
    else
    {
        while(i>=0)
        {
            if( a[i] == b[j] )
            {
                ans+=a[i];
                break;
            }
            i--;
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<ans;
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

