#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001
#define mod 1000000007
#define pi 3.141592653589793
#define all(v) v.begin(),v.end()
typedef vector<int> vi;
typedef vector<ll> vl;
ll gcd(ll a,ll b){
    if(b>a) swap(a,b);
    if(b==0) return a;
    return gcd(b,a%b);
}
ll lcm(ll a,ll b){
    ll g=gcd(a,b);
    return a/g*b;
}
ll rep_jijo(ll n,ll x){
    if(x==0) return 1;
    if(x%2==0){
        ll t=rep_jijo(n,x/2);
        return t*t%mod;
    }
    return n*rep_jijo(n,x-1)%mod;
}
ll com(ll n,ll r){
    ll x=1,y=1;
    ll tmp=n;
    while(tmp>=n-r+1){
        x=x*tmp%mod;
        tmp--;
    }
    while(r>0){
        y=y*r%mod;
        r--;
    }
    return x*rep_jijo(y,mod-2)%mod;
}

int main(){
    int n,k;
    cin >> n >> k;
    ll ans=inf;
    vector<int>ps;
    vector<int>ms;
    rep(i,n){
        int a;
        cin >> a;
        if(a>=0) ps.push_back(a);
        else ms.push_back(-a);
    }
    sort(all(ms));
    int ps_len=ps.size();
    int ms_len=ms.size();
    for(int a=0;a<=k;a++){
        ll mn;
        if(a==0){
            if(k>ms_len)continue;
            mn=ms[k-1];
        }
        else if(a==k){
            if(k>ps_len)continue;
            mn=ps[k-1];
        }
        else{
            if(ps_len<a)continue;
            if(ms_len<k-a)continue;
            mn=min(ps[a-1]*2+ms[k-a-1],ps[a-1]+ms[k-a-1]*2);
        }
        ans=min(ans,mn);
    }
    cout << ans << endl;

    return 0;
}
