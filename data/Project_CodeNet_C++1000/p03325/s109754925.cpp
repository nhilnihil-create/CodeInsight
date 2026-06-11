#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef long long ll;
const ll M=1000000007;
//------------------------------------------//
ll f(ll x){
    ll cnt=0;
    while(x%2==0){
        cnt++;
        x/=2;
    }
    return cnt;
}
int main(){
    ll N;cin>>N;
    ll ans=0;
    vector<ll> a(N);
    rep(i,N){
        cin>>a[i];
        ans+=f(a[i]);
    }
    cout<<ans<<endl;
}