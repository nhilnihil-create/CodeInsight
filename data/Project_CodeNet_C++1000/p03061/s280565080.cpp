#include <algorithm>
#include <bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;
#define rep(i, n) for (int i = 0; i <(int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
const ll MOD=1000000007;
const ll INF=1000000000000000001;
ll gcd(ll a, ll b) {
    return b ? gcd(b, a%b) : a;
}
int main(){
    ll n;cin>>n;
    ll a[n];
    rep(i,n)cin>>a[i];
    ll l[n]={0};
    ll r[n]={0};
    for(ll i=0;i<n;i++){
        l[0]=a[0];
        l[i+1]=gcd(l[i],a[i+1]);
    }
    for(ll i=n-1;i>=0;i--){
        r[n-1]=a[n-1];
        r[i-1]=gcd(a[i-1],r[i]);
    }
    ll ans=max(r[1],l[n-2]);
    for(ll i=1;i<n;i++){
        ll tmp=0;
        tmp=gcd(l[i-1],r[i+1]);
        ans=max(ans,tmp);
    }
    cout << ans << endl;
}