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
    vector<ll> x(n);
    vector<ll> x1(n);
    rep(i,n) {
        cin >> x[i];
        x1[i] = x[i];
    }
    sort(x.begin(),x.end());
    ll a,b;
    a = x[n/2];
    b = x[n/2-1];

    rep(i,n){
        if(x1[i]<b){
            cout << a << endl;
        }else if(x1[i]==b){
            cout << a << endl;
        }else if(x1[i]==a){
            cout << b << endl;
        }else{
            cout << b << endl;
        }
    }

    return 0;
}