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
    vector<ll> cnt(200010);
    rep(i,n){
        ll a;cin>>a;
        cnt[a]++;
    }
    sort(cnt.begin(),cnt.end(),greater<ll>());
    cnt.push_back(0);

    ll ans=0;
    for(ll i=k;cnt[i]!=0;i++){
        ans+=cnt[i];
    }

    cout<<ans<<endl;
    return 0;
}