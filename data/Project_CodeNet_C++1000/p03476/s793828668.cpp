#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long

int like2017(ll n){
    ll n2=(n+1)/2;
    bool ok1=true,ok2=true;
    for(ll i=2;i<n;++i){
        if(n%i==0) ok1=false;
    }
    for(ll i=2;i<n2;++i){
        if(n2%i==0) ok2=false;
    }
    if(ok1&&ok2) return 1;
    else return 0;
}

int main(void)
{
    int max=1e5+1;
    vector<ll> is_prime(max,1);
    is_prime[0]=is_prime[1]=0;
    for(int i=2;i<max;++i){
        if(!is_prime[i]) continue;
        for(int j=i*2;j<max;j+=i) is_prime[j]=0;
    }

    vector<ll> a(max,0);
    for(int i=0;i<max;i++){
        if(i%2==0) continue;
        if(is_prime[i]&&is_prime[(i+1)/2]) a[i]=1;
    }

    vector<ll> s(max+1,0);
    rep(i,max) s[i+1]=s[i]+a[i];

    ll q; cin>>q;
    rep(i,q){
        ll l,r; cin>>l>>r;
        cout<<s[r+1]-s[l]<<endl;
    }

    return 0;
}