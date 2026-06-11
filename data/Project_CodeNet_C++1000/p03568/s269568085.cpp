#include<bits/stdc++.h>
using namespace std;
using ll =long long;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define all(i) i.begin(),i.end()
template<typename T=ll> using v =vector<T>;
template<typename T=ll> using vv = vector<v<T>>;
template<typename T=ll,typename U=ll> using p = pair<T,U>;
const ll INF = (ll)1e9;
template<typename T> T chmin(T &a,T b){a=min(a,b);}
template<typename T> T chmax(T &a,T b){a=max(a,b);}


int main(){
    ll n; cin >> n;
    auto a = v<>(n,0);
    rep(i,n) cin >> a[i];
    ll ans = pow((ll)3,n);
  	ll bad = 1;
    bool gu = false;
    rep(i,n){
      bad*=a[i]%2?1:2;
    }
  	cout << ans -bad << endl;

}