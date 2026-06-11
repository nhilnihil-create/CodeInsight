#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define N               100005
#define ff              first
#define ss              second
#define ll              long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<ll,ll>
#define vi              vector<ll>
#define mii             map<ll,ll>
#define pq_max          priority_queue<ll>
#define pq_min          priority_queue<ll,vi,greater<ll> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            ll x; cin>>x; while(x--)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;


void fio(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

ll dp[405][405], a[405], sum[405][405];

void cSum(ll n){

    for(ll x=1;x<=n;x++){
        ll s = 0;
        for(ll y=x;y<=n;y++){
            s += a[y];
            sum[x][y] = s;
        }
    }

}

ll f(ll i, ll j){

    if(i == j) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    dp[i][j] = inf;
    for(ll k=i;k<j;k++){
        dp[i][j] = min(dp[i][j], f(i,k) + f(k+1,j) + sum[i][k] + sum[k+1][j]);
    }

    return dp[i][j];
}

int main(){
    fio();

    ll n;
    cin>>n;

    for(ll z=1;z<=n;z++) cin>>a[z];

    memset(dp, -1, sizeof dp);
    cSum(n);
    cout<<f(1,n);

    return 0;
}