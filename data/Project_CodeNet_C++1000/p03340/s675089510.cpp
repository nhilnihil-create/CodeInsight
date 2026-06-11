#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i=0;i<n;++i)
#define Graph vector<vector<ll>>
#define INF (1ll<<40-1)
#define mod 1000000007
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

vector<ll> sum;
void pre_process(vector<ll> &a,vector<ll> &s){//累積和のvector
    ll n=(ll)a.size();
    s.assign(n+1,0);
    for(ll i=0;i<n;i++){
        s[i+1]=s[i]+a[i];
    }
}

vector<ll> xorsum;
void pre_process_xor(vector<ll> &a,vector<ll> &s){//累積xorのvector
    ll n=(ll)a.size();
    s.assign(n+1,0);
    for(ll i=0;i<n;i++){
        s[i+1]=s[i]^a[i];
    }
}

int main(){
    ll n;cin>>n;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];

    pre_process(a,sum);
    pre_process_xor(a,xorsum);

    ll ans=0;
    ll left=0;
    for(ll right=1;right<=n;right++){
        while((xorsum[right]^xorsum[left])!=(sum[right]-sum[left])){
            left++;
        }

        ans+=right-left;
    }

    cout<<ans<<endl;

    return 0;
}