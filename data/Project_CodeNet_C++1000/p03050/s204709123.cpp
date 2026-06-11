#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep2(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
const ll INF = 1LL<<60;
const ll MOD = 1e9+7;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n; cin>>n;
    ll ans = 0;
    for(ll i=1; i*i<n; i++){
        ll m = (n-i)/i;
        if(n/m==n%m)ans+=(n-i)/i;
    }
    cout<<ans<<endl;
    return 0;
}