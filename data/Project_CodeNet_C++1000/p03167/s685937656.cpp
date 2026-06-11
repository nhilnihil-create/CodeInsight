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

const int mod=1e9+7;

char c[1100][1100];
int dp[1100][1100];


int main()
{

    int x,y;
    cin>>x>>y;
    
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<y;j++)
            cin>>c[i][j];
    }
    
    dp[0][0]=1;
    
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<y;j++)
        {
            if(c[i][j]=='#')continue;
            
            if(i>=1)dp[i][j]= (dp[i][j] + dp[i-1][j])%mod;
            if(j>=1) dp[i][j] = (dp[i][j] + dp[i][j-1])%mod;
            
        }
    }
    
    
    cout<<dp[x-1][y-1]<<endl;
}
