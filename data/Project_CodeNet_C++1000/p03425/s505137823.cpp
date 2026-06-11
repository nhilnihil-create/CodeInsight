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
    string w = "MARCH";
    vector<ll> a(5,0);
    rep(i,n){
        string s;
        cin >> s;
        rep(i,5){
            if(s[0]==w[i]) a[i]++;
        }
    }

    ll ans = 0;

    // rep(i,5){
    //     cout << a[i] << endl;
    // }

    for(ll i=0;i<3;i++){
        for(ll j=i+1;j<4;j++){
            for(ll k=j+1;k<5;k++){
                ans += a[i] * a[j] * a[k];
            }
        }
    }

    cout << ans << endl;



    return 0;
}