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
    fast_io;
    int n,k;
    cin>>n>>k;
    vi a(n);
    c(a,n);
    int m=1e9+7;
    vii dp(n,vi(k+1,0));
    for(int i=0;i<=min(k,a[0]);i++)dp[0][i]=1;
    int z=1;
    for(int i=1;i<n;i++)
    {
        vector<int>sum(k+1,0);
        sum[0]=dp[i-1][0];
        for(int j=1;j<=k;j++)sum[j]=(sum[j-1]%m+dp[i-1][j]%m)%m;
        for(int j=0;j<=k;j++)
        {
            int l=j-min(j,a[i])-1;
            dp[i][j]=sum[j];
            if(l>=0)
            dp[i][j]=(dp[i][j]-sum[l]+m)%m;
        }

        
    }
    
    
    cout<<dp[n-1][k]<<lc;
    return 0;
}