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
    ll n,y;
    cin >> n >> y;

    y/=1000;

    // cout << y << endl;

    for(ll i=0;i<=n;i++){
        for(ll j=0;j<=n;j++){
            if(n-i-j<0) continue;
            if(10*i + 5*j + (n-i-j) == y){
                cout << i << " " << j << " " << n-i-j << endl; 
                // cout << 10*i + 5*j + (tmp-j) << endl;
                // cout << now << endl;
                return 0;
            }
        }
    }

    cout << -1 << " " << -1 << " " << -1 << endl;

    return 0;
}