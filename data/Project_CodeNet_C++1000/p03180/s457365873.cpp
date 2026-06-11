#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int N = 16;
const int M = (1LL<<N);

const int inf = 1e14;

int n;
int a[N][N];
int dp[M];
int val[M];

signed main()
{
    fast;
    
    cin >> n;
    
    f(i,n) f(j,n) cin >> a[i][j];
  
    f(i,(1LL<<n)) f(j,n)    
               if(i&(1LL<<j))
               { 
                    val[i] = (val[i^(1LL<<j)]);
        
                    f(k,n) if(i&(1LL<<k)) val[i]+=a[j][k];
        
                    break;
               }
    
    dp[0] = 0;
    
    f(i,(1LL<<n))
        for(int j=i;;j=(j-1)&i)
    {
        dp[i] = max(dp[i],dp[j] + val[i^j]);
        if(j==0)break;
    }
    cout << dp[(1LL<<n)-1];
}