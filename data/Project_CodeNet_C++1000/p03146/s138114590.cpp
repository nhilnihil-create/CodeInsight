#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define P pair<ll, ll>
#define Graph vector<vector<ll>>
#define fi first
#define se second
constexpr ll mod = 1000000007;
constexpr ll INF = (1ll << 60);
constexpr double pi = 3.14159265358979323846;
template <typename T> inline bool chmax(T &a, T b){if (a < b){a = b;return 1;}return 0;}
template <typename T> inline bool chmin(T &a, T b){if (a > b){a = b;return 1;}return 0;}

int main(){
    ll s;cin>>s;
    vector<ll> a(1000001);
    vector<bool> check(5000000,false); 
    a[1]=s;
    for(ll i=2;i<=1000000;i++){
        if(a[i-1]%2==0){
            a[i]=a[i-1]/2;
        }else{
            a[i]=3*a[i-1]+1;
        }
    }

    ll ans=0;
    for(ll i=1;i<=1000000;i++){
        if(check[a[i]]==false){
            check[a[i]]=true;
        }else{
            ans=i;
            break;
        }
    }

    //rep(i,10) cout<<a[i]<<endl;

    cout<<ans<<endl;
    return 0;
}