/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lpair = pair<ll, ll>;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i=(m);i<(n);i++)
#define rrep(i,m,n) for(ll i=(m);i>=(n);i--)
#define printa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};
void print() {}
template <class H,class... T>
void print(H&& h, T&&... t){cout<<h<<" \n"[sizeof...(t)==0];print(forward<T>(t)...);}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,Z,W;
    cin >> N >> Z >> W;
    ll a[2010];
    rep(i,0,N) cin >> a[i];
    if(N == 1){
        print(abs(a[0] - W));
    }else{
        ll ans = max(abs(a[N-2] - a[N-1]), abs(a[N-1] - W));
        print(ans);
    }

    

}