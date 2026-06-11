//g++  5.4.0
// Time-complexity : ( 3^n * n + 2^n * n * n )
#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define int long long
#define pb push_back
#define pii pair< int,int >
#define fast ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;


signed main()
{
    fast;
    int n;
    cin >> n;
    int a[n][n];
    for(int i=0 ; i<n ; i++ )
    {
        for(int j=0 ; j<n ; j++ )
        {
            cin >> a[i][j];
        }
    }
    int sum[(1<<n)];
    memset( sum,0,sizeof(sum) );
    for(int mask=0 ; mask<(1<<n) ; mask++ )
    {
        for(int i=0 ; i<n ; i++ )
                    {
                        for(int j=i+1 ; j<n ; j++ )
                        {
                            if( (1<<i)&mask && (1<<j)&mask )
                                sum[mask] += a[i][j];
                        }
                    }
    }
    
    int dp[(1<<n)];
    memset( dp,0,sizeof(dp) );
    
    for(int mask=0 ; mask<(1<<n) ; mask++ )
    {
                int dummy_mask = mask;
                while( dummy_mask )
                {
                    dp[mask] = max( dp[mask] ,  sum[dummy_mask] + dp[ mask^dummy_mask ] );
                    dummy_mask = ( mask&(dummy_mask-1) );
                }
           
    }
    
    
    cout << dp[(1<<n)-1];
}



