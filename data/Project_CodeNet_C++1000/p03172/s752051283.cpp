#include <bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define pb push_back
#define si second
#define int long long
#define mod 1000000007
#define debug(x) cout << #x << " " << x <<endl;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define double long double
#define all(o) o.begin(),o.end()
using namespace std;
int power(int x, int y)
{
    int res = 1;
    x = x % mod;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % mod;
        y = y>>1; // y = y/2
        x = (x*x) % mod;
    }
    return res%mod;
}
int inv(int  n)
{
    return power(n,mod-2)%mod;
}
int dp[105][100005],a[1005];
int32_t main(){
   //fast
   int n,q,i,j,k;
   cin>>n>>q;
   for(i=1;i<=n;i++)
       cin>>a[i];



   for(i=0;i<=q;i++)
       dp[0][i]=1;
    



    for(i=0;i<=n;i++)
        dp[i][0]=1;


   for(i=1;i<=n;i++)
   {
        for(j=1;j<=q;j++){
            int l=j-a[i]-1;
            dp[i][j]=dp[i-1][j];
            
            if(l>=0)
            {
                dp[i][j]-=dp[i-1][l];
                if(dp[i][j]<0)
                    dp[i][j]+=mod;
            }
            dp[i][j]+=dp[i][j-1];
            dp[i][j]%=mod;
        }
    }
    
    cout<<(dp[n][q]-dp[n][q-1]+mod)%mod<<"\n";
    

}