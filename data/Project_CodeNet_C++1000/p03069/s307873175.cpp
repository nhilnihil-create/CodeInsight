#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(ll i=0;i< (n);i++)
#define rep1(i,n) for(ll i=1;i<= (n);i++)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

const static ll MOD = (1e+9)+7;

ll modpow(ll a,ll n){
    if(n==0)return 1;
    if(n%2==1)return a*modpow(a,n-1)%MOD;
    ll t = modpow(a,n/2) % MOD;
    return t*t % MOD;
}

int main(){
    ll n;cin>>n;
    vector<bool> A(n,0);
    ll num_w=0;
    rep(i,n){
        char tmp;cin>>tmp;
        if(tmp == '#')A[i]=1;
        else num_w++;
    }
    vector<ll> lst(n+1,-1);
    lst[0] = num_w;
    rep1(i,n){
        if(A[i-1]==1){
            lst[i] = lst[i-1]+1;
        }else{
            lst[i] = lst[i-1]-1;
        }
    }
    ll ans = MOD;
    rep(i,n+1){
        ans = min(ans,lst[i]);
    }
    cout<<ans<<endl;
    return 0;
}