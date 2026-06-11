#include<bits/stdc++.h>
#define pi pair<int,int>
#define mk make_pair
#define f(i,n) for(int i=0;i<n;i++)
#define fo(i,a,n) for(int i=a;i<n;i++)
#define fr(i,a,n) for(int i=a;i>=n;i--)
#define ll long long
#define N 1000000007
using namespace std;

int h,w;
vector<vector<int>> dp(1005,vector<int> (1005,-1));
char grid[1005][1005];

ll path_cost(int i,int j)
{
    if(i==h&&j==w)
        return 1;
    if(grid[i][j]=='#')
        return 0;
    if(i>h||j>w)
        return 0;

    if(dp[i][j]==-1)
        dp[i][j] = (path_cost(i+1,j)+path_cost(i,j+1))%N;
    return dp[i][j];
}


int main()
{
    //int h,w;
    cin>>h>>w;
    //char grid[h+1][w+1];
    fo(i,1,h+1)
    {
        fo(j,1,w+1)
        {
            cin>>grid[i][j];
        }
    }
    ll ans=path_cost(1,1);
    cout<<ans;
}
