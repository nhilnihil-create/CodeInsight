#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){return b!=0?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}

int main(){
    ll n,sum=0;
    cin>>n;
    vector<ll> a(n+2);
    a[0]=0;
    rep(i,n){
        cin>>a[i+1];
        sum+=abs(a[i+1]-a[i]);
    }
    a[n+1]=0; sum+=abs(a[n]);
    rep(i,n) cout<<sum-abs(a[i+1]-a[i])-abs(a[i+2]-a[i+1])+abs(a[i+2]-a[i])<<endl;
    return 0;
}