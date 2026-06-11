#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef long double ld;
typedef array<ll,2> pll;
const ll NMAX=3005,MOD=1e9+7;
ld dp[NMAX][NMAX];

int main()
{
    ll n;
    ld p,ans=0;
    cin>>n;
    dp[0][0]=1;
    for(ll i=1;i<=n;i++){
        cin>>p;
        for(ll cnt=0;cnt<=i;cnt++){
            dp[i][cnt]=dp[i-1][cnt-1]*p+dp[i-1][cnt]*(1-p);
        }
    }
    for(ll i=n/2+1;i<=n;i++)
        ans+=dp[n][i];
    cout<<fixed<<setprecision(9)<<ans;
    return 0;
}
