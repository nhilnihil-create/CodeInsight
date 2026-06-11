#include <bits/stdc++.h>
#define ROCK ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define f first
#define sec second
using namespace std;
typedef long long ll;
const long long int linf =(ll)9e18;
const int dx[8] = { 0, 0, 1, -1, 1, -1, 1, -1 }, dy[8] = { 1, -1, 0, 0, 1, -1, -1, 1 };

const int N=1005,MOD=(int)1e9+7;
ll n,m,dp[N][N];
char grid[N][N];

bool isvalid(int i,int j){
    return i>=0 && i<n && j>=0 && j<m && grid[i][j]!='#';
}

ll solve(int i,int j){
   if(i==n-1 && j==m-1)return 1;
   ll &ret=dp[i][j];
   if(~ret)return ret;
   ll right=0;
   if(isvalid(i+1,j))right=solve(i+1,j);
   ll down=0;
   if(isvalid(i,j+1))down=solve(i,j+1);
   return ret=(right%MOD + down%MOD)%MOD;
}

int main()
{
    ROCK;
    memset(dp,-1,sizeof dp);
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>grid[i][j];
    cout<<solve(0,0)<<endl;
    return 0;
}