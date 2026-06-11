#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){return b!=0?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}

int main(){
    ll n;
    cin>>n;
    vector<ll> c(n-1),s(n-1),f(n-1);
    rep(i,n-1) cin>>c[i]>>s[i]>>f[i];
    rep(i,n-1){
        ll t=0;
        for(ll j=i;j<n-1;j++){
            if(t<=s[j]) t=s[j];
            else t=(t+f[j]-1)/f[j]*f[j];
            t+=c[j];
        }
        cout<<t<<endl;
    }
    cout<<0<<endl;
    return 0;
}