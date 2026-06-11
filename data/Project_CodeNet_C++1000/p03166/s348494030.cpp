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
int dp[100001];

int path_length(int node,vector<vector<int>> &graph)
{
    int temp=0;
    for(auto child:graph[node])
    {
        temp=max(temp,(1+(dp[child]!=-1?dp[child]:path_length(child,graph))));
    }
    return dp[node]=temp;
}

int solve(vector<vector<int>> &graph,int n)
{
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=n;i++)
    {
        if(dp[i]==-1)
           path_length(i,graph); // this will return the length of the longest path starting from 
           // node i......if uska koi child nhi hai tu in taht case length will be zero..
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,dp[i]);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n,m;
    cin>>n>>m;
    vector<vector<int>> graph(n+1);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].pb(b);  // directed graph hai...
    }
    cout<<solve(graph,n);
    

    return 0;
}





