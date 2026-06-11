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
    ll n,k;
    cin >> n >> k;
    vector<ll> a(n);
    ll p;
    rep(i,n) {
        cin >> a[i];
        if(a[i]==1) p = i + 1;
    }

    // ll r,l;
    // r = n - p;
    // l = p - 1;

    // ll ans = 0;

    // if(r%(k-1)!=0&&l%(k-1)!=0){
    //     ans += 1;
    //     r--;
    //     l--;
    //     ans += (l + k - 2)/(k - 1) + (r + k - 2)/(k - 1);
    // }else{
    //     ans += (l + k - 2)/(k - 1) + (r + k - 2)/(k - 1);
    // }
    
    ll ans = (n - 1 + k - 2)/(k - 1);

    cout << ans;

    return 0;
}