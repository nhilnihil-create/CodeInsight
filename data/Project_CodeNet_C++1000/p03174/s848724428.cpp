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

ll dp[22][(1ll<<22)];

ll helper(ll i, ll j, vector<vector<ll> >& v){
    if(i==v.size()){
        if(j==0) return 1;
        else return 0;
    }
    if(dp[i][j]!=-1) return dp[i][j];
    ll ans = 0;
    for(ll w=0; w<v.size(); w++){
        if(((1ll<<w)&j)&&v[i][w]){
            ans+=helper(i+1, (j^(1ll<<w)), v);
            ans%=mod;
        }
    }
    return dp[i][j] = ans;
}

int main(){
    cpp();
    ll n;
    cin>>n;
    memset(dp, -1, sizeof dp);
    vector<vector<ll> > v(n, vector<ll>(n));
    for(ll i=0; i<n; i++){
        for(ll j=0; j<n; j++){
            cin>>v[i][j];
        }
    }
    cout<<helper(0, ((1ll<<n)-1) , v);
    return 0;
}




