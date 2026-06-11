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

ll f(ll *a, ll i, ll j){

    ll dp[i+5][j+5];

    for(ll x=0;x<=j;x++) {
        if(x <= a[1]) dp[1][x] = 1;
        else dp[1][x] = 0;
    }

    for(ll x=2;x<=i;x++){
        for(ll y=0;y<=j;y++){
            if(y == 0) dp[x][y] = dp[x-1][y];
            else{
                dp[x][y] = (mod + dp[x-1][y] + dp[x][y-1] - ((y - a[x] - 1 >= 0) ? dp[x-1][y - a[x] - 1] : 0)) % mod;
            }
        }
    }

    return dp[i][j];
}

int main(){
    fio();

    ll n, k;
    cin>>n>>k;

    ll a[n+1];
    for(ll z=1;z<=n;z++) cin>>a[z];

    cout<<f(a, n, k);

    return 0;
}