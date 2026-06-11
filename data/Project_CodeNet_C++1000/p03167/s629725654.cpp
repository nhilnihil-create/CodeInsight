#include<bits/stdc++.h>
using namespace std;
#define lc "\n"
#define fast_io ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(0)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define int long long
#define c(a,n) for(int i = 0; i < n; i++) cin >> a[i];
#define ffor(n) for(int i = 0; i < n; i++)
 
typedef vector<int> vi;
typedef vector<float> vf;
typedef vector<vi> vii;
typedef vector<string> vs;
typedef vector<long long> vll;
typedef map<string,int> msi;
typedef map<int,int> mii;
typedef unordered_map<string,int> umsi;
 
 
int32_t main()
{
    int mod=1e9+7;
    fast_io;
    int n, m;
    cin>>n>>m;
    vector<vector<char>>grid(n,vector<char>(m));
    for(int i=0;i<n;i++)
        for(int j=0; j<m; j++)cin>>grid[i][j];
    vii dp(n+2,vi(m+2,0));
    for(int i=1;i<=n;i++){
        if(grid[i-1][0]=='#')break;
        else dp[i][1]=1;
    }
    for(int i=1;i<=m;i++){
        if(grid[0][i-1]=='#')break;
        else dp[1][i]=1;
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=2;j<=m;j++)
        {
            if(grid[i-1][j-1]!='#'){
            dp[i][j]+=dp[i-1][j];
            dp[i][j]+=dp[i][j-1];
            dp[i][j]%=mod;
            }

        }
    }
    cout<<dp[n][m];
    return 0;
}