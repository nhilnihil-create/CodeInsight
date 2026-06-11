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
#define float long double
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
    
       int n;
       cin>>n;
       vector<float> a(n);
       c(a,n);
       vector<vector<float>>dp(n+1,vector<float>(n+1,0.00));
       dp[1][1]=a[0];
       dp[1][0]=1-a[0];
       for(int i=2;i<=n;i++)
       {
           for(int j=0;j<=i;j++)
            {
                if(j==0){
                    dp[i][j]=(1.00-a[i-1])*dp[i-1][j];
                    continue;
                }
                if(j==i){
                    dp[i][j]=dp[i-1][j-1]*a[i-1];
                    continue;
                }
                dp[i][j]+=(a[i-1]*dp[i-1][j-1]);
                dp[i][j]+=(dp[i-1][j]*(1.00-a[i-1]));
            }

       }       
       float ans=0.00;
       for(int i=n/2+1;i<=n;i++)
       ans+=dp[n][i];
       cout<<setprecision(10)<<ans<<lc;
    
    return 0;
}