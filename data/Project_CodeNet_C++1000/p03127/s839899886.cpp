#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001
#define mod 1000000007
#define mod2 998244353
#define pi acos(-1)
#define all(v) v.begin(),v.end()

int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};


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


int main(){
    int n;
    cin >> n;
    vector<ll>a(n);
    rep(i,n) cin >> a[i];
    ll ans = 0;
    rep(i,n){
        ans = gcd(ans,a[i]);
    }
    cout << ans << endl;
    return 0;
}
