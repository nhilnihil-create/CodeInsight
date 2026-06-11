#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
using namespace std;
typedef long long ll;

ll gcd(ll a,ll b){return b!=0?gcd(b,a%b):a;}

int main(){
    ll n;
    cin>>n;
    vector<ll> a(n),gcdl(n),gcdr(n);
    rep(i,n) cin>>a[i];
    gcdl[0]=a[0],gcdr[n-1]=a[n-1];
    for(ll i=1;i<n;i++) gcdl[i]=gcd(gcdl[i-1],a[i]);
    for(ll i=n-2;i>=0;i--) gcdr[i]=gcd(gcdr[i+1],a[i]);
    ll mx=gcdr[1];
    for(ll i=1;i<n-1;i++) mx=max(mx,gcd(gcdl[i-1],gcdr[i+1]));
    mx=max(mx,gcdl[n-2]);
    cout<<mx<<endl;
    return 0;
}