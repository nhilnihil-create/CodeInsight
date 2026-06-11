/*
    Author - Param Kothari
    Ah shit, here we go again
*/

#include <bits/stdc++.h>
 
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define mk make_pair

typedef long long ll;
typedef long double ld;

ll f(ll n){
    ll res = n - n % 4;
    for(ll m = res + 1; m <= n; m++){
        res ^= m;
    }
    return res;
}

void solve(){
    ll a, b;
    cin >> a >> b;
    cout << (f(b) ^ f(a - 1)) << "\n";
    return;
}

int main(){
    IOS;
    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i++){
        solve();
    }
    return 0;
}