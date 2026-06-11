#include <bits/stdc++.h>
#define rep(a,n) for (ll a = 0; a < (n); ++a)
using namespace std;
using ll = long long;
typedef pair<ll,ll> P;
typedef pair<P,ll> PP;
typedef vector<vector<ll> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e18;

//入力
ll n,k;
vector<ll>a;

bool ok(ll keta,vector<ll>v){
    ll res = 0;
    ll l = v.size();
    rep(i,l){
        if((v[i]>>keta)&1){
            res++;
        }
    }
    if(res>=k)return true;
    return false;
}

vector<ll>furui(ll keta,vector<ll>v){
    ll l = v.size();
    vector<ll>res;
    rep(i,l){
        if((v[i]>>keta)&1){
            res.push_back(v[i]);
        }
    }
    return res;
}

int main(){
    cin >> n >> k;
    a.resize(n);
    vector<ll>v;
    rep(i,n){
        cin>>a[i];
    }
    vector<ll>rui(n+1,0);
    rep(i,n){
        rui[i+1]=rui[i]+a[i];
    }
    for(ll i=0;i<n;i++){
        for(ll j=i+1;j<=n;j++){
            v.push_back(rui[j]-rui[i]);
        }
    }
    ll ans = 0;
    for(ll i=40;i>=0;i--){
        if(ok(i,v)){
            v = furui(i,v);
            ans += pow(2,i);
        }
    }
    cout << ans << endl;
    return 0;
}
