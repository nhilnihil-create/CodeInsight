//Author rahuliitkgp

/*A thing of beauty is a joy forever,
Its loveliness increases,
it will never pass into nothingness.*/
//Men at Work :)

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long int ll;

#define setbits(x)      __builtin_popcountll(x)
#define mod             1000000007
#define ps(x,y)         fixed<<setprecision(y)<<x
#define w(x)            int x; cin>>x; while(x--)
#define INF (int)1e9 + (int)1e8
mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void cpp(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

ll dp[101][100004];

int main(){
    cpp();
    ll n, k;
    cin>>n>>k;
    vector<ll> v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }
    dp[0][0] = 1;
    for(ll i=1; i<=n; i++){
        for(ll j=0; j<=k; j++){
            if(j==0){
                dp[i][j] = dp[i-1][j];
                dp[i][j]%=mod;
                continue;
            }
            dp[i][j] = dp[i][j-1]+dp[i-1][j]-((j-1-v[i-1]>=0)?dp[i-1][j-1-v[i-1]]:0);
            dp[i][j]%=mod;
            dp[i][j]=(dp[i][j]+mod)%mod;
        }
    }
    cout<<dp[n][k]<<endl;
    return 0;
}




