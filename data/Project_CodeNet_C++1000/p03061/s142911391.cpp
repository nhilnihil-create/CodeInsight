#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> fac(ll n){
    vector<ll> v;
    for (int i=1; i<=sqrt(n); i++){
        if (n%i==0){
            if (i == n/i)v.push_back(i);
            else {
                v.push_back(i);
                v.push_back(n/i);
            }
        }
    }
    return v;
}
ll check(vector<ll> v, ll n){
    ll ans = n;
    for (int i=0; i<=v.size(); i++){
        if (n*v[i] <= ll(1e9))ans = n*v[i];
    }
    return ans;
}
int main(){
    int n; cin>>n;
    ll a[n];
    for (int i=0; i<n; i++)cin>>a[i];
    ll l[n], r[n];
    l[0] = a[0], r[n-1] = a[n-1];
    for (int i=1; i<n; i++)l[i] = __gcd(l[i-1], a[i]);
    for (int i=n-2; i>=0; i--)r[i] = __gcd(r[i+1], a[i]);
    // for (int i=0; i<n; i++)cout<<l[i]<<" ";cout<<endl;
    // for (int i=0; i<n; i++)cout<<r[i]<<" ";cout<<endl;
    ll arrgcd = r[0];
    ll ans = arrgcd;
    for (int i=0; i<n; i++){
        if (i==0){
            ll left = 0, right = r[i+1];
            ll gcd = __gcd(left, right);
            ans = max(ans, gcd);
        }
        else
        if (i==n-1){
            ll left = l[n-2], right = 0;
            ll gcd = __gcd(left, right);
            ans = max(ans, gcd);
        }
        else{
            ll left = l[i-1], right = r[i+1];
            ll gcd = __gcd(left, right);
            ans = max(ans, gcd);
        }
        // cout<<ans<<endl;
    }
    cout<<ans<<endl;
}