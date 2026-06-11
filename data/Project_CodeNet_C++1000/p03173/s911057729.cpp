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

ll dp[401][401];

ll helper(ll s, ll e, vector<ll>& prefix){
    if(s>=e) return 0;
    if(dp[s][e]!=-1) return dp[s][e];
    ll x = prefix[e]-prefix[s-1];
    ll temp = LLONG_MAX;
    for(ll i=s; i<=e-1; i++){
        temp = min(temp, helper(s, i, prefix)+helper(i+1, e, prefix));
    }
    x+=temp;
    return dp[s][e]=x;
}

int main(){
    cpp();
    ll n;
    cin>>n;
    memset(dp, -1, sizeof dp);
    vector<ll> prefix(n+1);
    for(ll i=1; i<prefix.size(); i++){
        cin>>prefix[i];
        prefix[i]+=prefix[i-1];
    }
    cout<<helper(1, n, prefix)<<endl;
    return 0;
}




