#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int sum_(ll i){
    ll sum = 0;
    while(i > 0){
        sum += i % 10;
        i /= 10;
    }
    return sum;
}

int main(){
    ll n, a, b;
    cin >> n >> a >> b;
    ll ans = 0;
    for(ll i = 1; i <= n; i++){
        ll sum = sum_(i);
        if(sum >= a && sum <= b){
            ans += i;
        }
    }
    cout << ans << endl;
}
   