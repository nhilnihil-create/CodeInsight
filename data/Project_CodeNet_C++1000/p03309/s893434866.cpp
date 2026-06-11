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
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    rep(i,n) a[i] = a[i] - (i+1);

    sort(a.begin(),a.end());

    // int mi = a[0];

    // rep(i,n) a[i] = a[i] - mi;

    // int sum = 0;
    // rep(i,n) sum += a[i];

    // sum = sum/n;

    // if(sum>=0){
    //     sum = sum/n;
    // }else{
    //     sum = -(abs(sum)+n-1)/n;
    // }


    // rep(i,n) a[i] = a[i] - sum;

    ll ans = 0;

    // int m = n/2;

    // int q = a[m];

    ll tmp;

    if(n%2==1){
        tmp = a[n/2];
    }else{
        tmp = (a[n/2] + a[n/2 - 1])/2;
    }
    // cout << tmp << endl;

    // rep(i,n) cout << a[i] << endl;

    rep(i,n) ans += abs(a[i] - tmp);

    cout << ans;

    return 0;
}