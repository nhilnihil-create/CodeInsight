#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(long long i=0;i<n;++i)
#define P pair<ll,ll>
#define Graph vector<vector<ll>>
#define fi first
#define se second
constexpr ll INF=(1ll<<60);
constexpr ll mod=1000000007;
constexpr double pi=3.14159265358979323846;
template<typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    vector<ll> a(5);
    ll ans=0;
    rep(i,5){
        cin>>a[i];
    }

    ll MIN=11,key;
    rep(i,5){
        if(MIN>(a[i]%10==0?10:a[i]%10)){
            MIN=(a[i]%10==0?10:a[i]%10);
            key=i;
        }
    }

    rep(i,5){
        if(i==key){
            ans+=a[key];
        }else{
            ans+=(a[i]+9)/10*10;
        }
    }

    cout<<ans<<endl;
    return 0;
}