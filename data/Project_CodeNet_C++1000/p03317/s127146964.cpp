#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define P pair<ll, ll>
#define Graph vector<vector<P>>
#define fi first
#define se second
constexpr ll mod = 1000000007;
constexpr ll INF = (1ll << 60);
constexpr double pi = 3.14159265358979323846;
template <typename T>inline bool chmax(T &a, T b){if (a < b){a = b;return 1;}return 0;}
template <typename T>inline bool chmin(T &a, T b){if (a > b){a = b;return 1;}return 0;}

int main(){
    ll n,k;cin>>n>>k;
    vector<ll> a(n);

    ll key;
    rep(i,n){
        cin>>a[i];
        if(a[i]==1) key=i;
    }

    ll ans=INF;
    for(ll i=max(0ll,key-(k-1));i<=key;i++){
        ll sum=0;
        sum++;
        sum+=(i+k-2)/(k-1);
        sum+=(n-1-min(n-1,i+k-1)+k-2)/(k-1);

        chmin(ans,sum);
    }

    cout<<ans<<endl;
    return 0;
}