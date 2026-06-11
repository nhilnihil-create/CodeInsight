#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string>
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using namespace std;
#define P pair<int, int>

int main () {
    ll n , m , ans ;
    cin >> n >> m ;
    if(n == 1 || m == 1){
         if(n == 1){
             if(m == 1){
                 ans = 1 ;
             }else {
             ans = (m - 2) * n ;
             }
         }else{
             if(n == 1){
                 ans = 1 ;
             }else{
             ans = (n - 2) * m ;
             }
         }
    }else{
        ans = (n - 2) * (m - 2) ;
    }

    if(ans <= 0){
        cout << 0 << endl;
    }else{
        cout << ans << endl;
    }
    return 0 ;
}

 
