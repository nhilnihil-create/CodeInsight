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
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    vector<ll> c(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    rep(i,n) cin >> c[i];

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    sort(c.begin(),c.end());

    ll ans = 0;

    rep(i,n){

        vector<ll>::iterator j,k;
        // auto j,k;

        j = lower_bound(a.begin(),a.end(),b[i]);
        k = upper_bound(c.begin(),c.end(),b[i]);

        ll dis1,dis2;

        dis1 = distance(a.begin(),j);
        dis2 = distance(k,c.end());

        ans += (dis1)*(dis2);

    }

    cout << ans << endl;

    return 0;
}