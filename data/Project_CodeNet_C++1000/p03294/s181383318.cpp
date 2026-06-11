#include<bits/stdc++.h>
using namespace std;
using ll=long long;

//GCD,LCM
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

int main(){
    ll n;
    cin>>n;
    ll a[100010];
    int ans=0;
    for(int i=0;i<n;++i)cin>>a[i];
    // sort(a,a+n-1);
    // ll l=lcm(a[0],a[1]);
    // for(int i=2;i<n;++i){
    //     l=lcm(l,a[i]);
    // }
    // ll m=l-1;
    // for(int i=0;i<n;++i){
    //     ans+=m%a[i];
    // }
    for(int i=0;i<n;++i)ans+=a[i]-1;
    cout<<ans<<endl;
    return 0;
}