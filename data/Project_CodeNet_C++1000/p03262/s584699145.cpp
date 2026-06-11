#include <cstdio>
#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#define rep(i,n) for (int i=0;i<n;i++)
using ll = long long;
using namespace std;

void solve(){

}
int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    ll x;
    cin >> n;
    cin >> x;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    // sort(a.begin(),a.end());
    rep(i,n){
        a[i] = abs(a[i] - x);
    }
    ll ans = a[0];
    rep(i,n){
        ans = __gcd(ans,a[i]);
    }
    cout  << ans << endl;

    return 0;
}