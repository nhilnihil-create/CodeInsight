#include"bits/stdc++.h"
 

#define rep(i,a,n) for (int i = a; i <= n; i++)

#define ll long long int

//const int mod=1000000007;
using namespace std;
 
/*int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, -1, 1};
*/


vector<int> g[110000];
int dp[110000];

int solve(int a)
{
    if(dp[a]!=-1)
        return dp[a];
    
    int ret=0;
    for(int i=0;i<g[a].size();i++)
    {
        
        ret=max(ret, solve(g[a][i])+1 );
        
    }
    
    return dp[a]=ret;
}



int main()
{

    
    int a,b;
    cin>>a>>b;
    
    for(int i=0;i<b;i++)
    {
        int x,y;
        cin>>x>>y;
        
        x--;y--;
        g[x].push_back(y);
        
    }

    memset(dp,-1,sizeof(dp));
    int ret=0;
    for(int i=0;i<a;i++)
    {
        ret= max(ret, solve(i));
        
    }
    
    cout<<ret<<endl;
    
    
}
