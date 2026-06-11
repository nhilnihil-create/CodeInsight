#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define N               200005
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

ll a[N], h[N];

struct Bit{
   ll b[N] = {};

   void update(ll i, ll val){
       while(i < N){
           b[i] = max(b[i], val);

           i += (i & (-i));
       }
   }

   ll query(ll i){
       ll ans = 0;

       while(i > 0){
           ans = max(ans, b[i]);
           i -= (i & (-i));
       }

       return ans;
   }

} f;

int main(){
    fio();

    ll n;
    cin>>n;

    for(ll z=1;z<=n;z++) cin>>h[z];
    for(ll z=1;z<=n;z++) cin>>a[z];

    ll res = INT16_MIN;
    for(ll x=1;x<=n;x++){
        ll q = f.query(h[x] - 1);

        res = max(res, q + a[x]);
        f.update(h[x], q + a[x]);
    }

    cout<<res;

    return 0;
}