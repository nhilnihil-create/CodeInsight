#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define rrep(i,n) for(ll i=(n)-1;i>=0;i--)
template<typename T =ll> using v = vector<T>;
template<typename T =ll> using vv = v<v<ll>>;
template<typename T=ll,typename U=ll> using p = pair<T,U>;
template<typename T> T chmin(T &a,T b) {return a=min(a,b);}
template<typename T> T chmax(T &a,T b) {return a=max(a,b);}
const ll INF = (ll)1e9;

ll misum =0;
ll func(ll i,const v<> &c){
    if(i>=c.size()||misum>=0)return 0;
    misum+=c[i];
    return func(i+1,c)+1;
}

int main(){
    
    ll n; cin  >>  n;
    auto a = v<>(n,0);
    auto b = v<>(n,0);
    auto c = v<>(n,0);
    
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    rep(i,n) c[i] = a[i]-b[i];
    sort(c.begin(),c.end());
    
    ll ans =count_if(c.begin(),c.end(),[](ll i)mutable{
            if(i<0) {
                misum+=i;
                return true;
            }
            return false;
        });
    
    if(accumulate(c.begin(),c.end(),(ll)0)<0){
        cout << -1 << endl;
        return 0;
    }

    sort(c.begin(),c.end(),greater<ll>());
    cout << ans+func(0,c);
    
    return 0;
}