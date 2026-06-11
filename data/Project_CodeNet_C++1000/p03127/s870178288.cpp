#include <algorithm>
#include <bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;
#define rep(i, n) for (int i = 0; i <(int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
const ll MOD=1000000007;
const ll INF=1<<29;
ll gcd(ll a, ll b) {
    return b ? gcd(b, a%b) : a;
}
ll ngcd(vector<ll> a){
    ll res;
    res = a[0];
    for(ll i = 1; i < a.size() && res != 1; i++) {
        res = gcd(a[i], res);
    }
    return res;
}
int main(){
    ll n;cin>>n;
    vector<ll> a(n);
    rep(i,n)cin>>a[i];
    ll ans=0;
    ans=ngcd(a);
    cout << ans << endl;

}