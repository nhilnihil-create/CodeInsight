#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e18
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const ll MOD = 1e9 + 7;
ll dp[30][(1<<22)];

int ara[30][30];

int main()
{
    fastRead;
    int n;
    cin>>n;
    
    for(int i =1 ; i <=n ; i++ ) {
        for(int j =1 ; j <=n ; j++ ) {
            cin>>ara[i][j];
        }
    }
    dp[0][0] = 1;
    for(int i =1 ; i <=n ; i++ ) {
        
        for(int j = 1; j< (1<<n) ; j++ ) {
            
            if(__builtin_popcount(j) != i) continue;
            for(int k =1 ; k <= n ;k++ ) {
                if(ara[i][k] == 0 || ( j &(1<<(k-1)) ) == 0 ) continue;
                
                dp[i][j] = (dp[i][j] + dp[i-1][ ( j ^(1<<(k-1)) ) ] ) % MOD;
            }
        }
    }
    cout<<dp[n][(1<<n)-1]<<'\n';
    return 0;
}