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
    ll n,m;cin>>n>>m;
    vector<P> ab(n);
    rep(i,n){
        cin>>ab[i].fi>>ab[i].se;
    }
    sort(ab.begin(),ab.end());

    ll ans=0,check=0;
    rep(i,n){
        if(check+ab[i].se<=m){
            ans+=(ab[i].se*ab[i].fi);
            check+=ab[i].se;
            if(check==m) break;
        }else{
            ans+=(m-check)*ab[i].fi;
            break;
        }
    }

    cout<<ans<<endl;
    return 0;
}