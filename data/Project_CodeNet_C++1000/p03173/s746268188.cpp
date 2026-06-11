/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mod 1000000007
ll dp[401][401];

ll cost(int i,int j,vector<ll> &v)
{
    if(i>=j)
    {
        return 0; // it simply means their is already a single slime....i==j
    }
    else
    {
        if(dp[i][j]!=-1)
           return dp[i][j]; // recursion+memoisation...
           
        ll ans=LLONG_MAX;
        ll sum=0;
        for(ll k=i;k<=j;k++)
        {
            sum+=v[k]; // ye current slime ko banane ka cost hai....
        }
        for(int k=i;k<=j-1;k++)
        {
            ans=min(ans,(dp[i][k]!=-1?dp[i][k]:cost(i,k,v))+(dp[k+1][j]!=-1?dp[k+1][j]:cost(k+1,j,v))+sum);
        }
        return dp[i][j]=ans;
    }
}

ll solve(int n,vector<ll> &v)
{
    memset(dp,-1,sizeof(dp));
    return cost(1,n,v);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin>>n;
    vector<ll> v(n+1);
    for(ll i=1;i<=n;i++)
    {
        cin>>v[i];
    }
    cout<<solve(n,v);
    return 0;
}





