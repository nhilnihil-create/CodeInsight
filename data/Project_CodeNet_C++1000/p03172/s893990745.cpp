#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
double pi = acos(-1.0);
const double EPS=1e-9;
#define MOD ll(1e9L+7)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define t() ll tt;cin>>tt;while(tt--) 
#define t2() ll tt2; cin>>tt2; for(ll tti=1;tti<=tt2;tti++)
#define printcj "Case #"<<tti<<": "
#define debug1(x) cerr << #x << " = " << x << '\n';
#define debug2(x, y) cout << #x << " = " << x << "   " << #y << " = " << y << "\n";

const ll N=101,K=100001;
ll n,k,a[N];
ll dp[K];

int main()
{
    fastio;
    ll i,j,x;
    cin>>n>>k;
    for(i=0;i<n;i++)cin>>a[i];

    for(j=0;j<=k;j++)dp[j] = 0;
    //  dp[j] = no of ways such that sum of candies is j
    // dp[j] += dp[j-x] ; where x => [1,a[i]]

    /*NOTE 
        dp[i][j] = 0;
        for(x=0 to x=a[i]) dp[i][j] += dp[i-1][j-x]
        similarly
            dp[j]=0;
            dp[j] = dp[j] + dp[j-1] + ...... + dp[j-x]
        // we start x from 1  
            dp[j] += dp[j-1] + ......... + dp[j-x]
        //for fast access use prefix sum/sliding window type approach
    */  



    //base case 
    dp[0]=1;

    for(i=0;i<n;i++){
        ll L=max(0LL,k-a[i]),R=k; //window of [L,R]
        ll sum=0; //window sum
        for(j=L;j<=R;j++) sum = (sum+dp[j])%MOD;

        for(R=k;R>=0;R--){
            ll temp = dp[R];
            dp[R] = sum;
            sum = (sum-temp+MOD)%MOD;
            if(L!=0){
                L--;
                sum = (sum+dp[L])%MOD;
            }
        }
    }
    cout<<dp[k];

    
}