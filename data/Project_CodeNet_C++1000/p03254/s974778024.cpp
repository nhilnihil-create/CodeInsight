#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    ::sort(a.begin(), a.end());

    ll sum = 0;
    ll ans = 0;

    rep(i, n) {
        sum += a[i];
        if(sum > x) {
            break;
        }
        if(sum <= x){
            ans++;
        }
    }
    if(sum<x){
        ans--;

    }
    cout << ans << endl;
}