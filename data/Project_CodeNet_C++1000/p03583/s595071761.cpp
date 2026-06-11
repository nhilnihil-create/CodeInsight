#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b){
    if(a % b == 0) return b;
    return gcd(b, a % b);
}

int main(){
    ll N; cin >> N;
    ll w;
    for(ll i = 1; i <= 3500; i++){
        for(ll j = 1; j <= 3500; j++){
            ll s = i + j, m = i * j;
            if(gcd(4*m - N*s, N*m) == 4*m - N*s){
                w = N*m/gcd(4*m - N*s, N*m);
                if(w < 0) continue;
                cout << i << " " << j << " " << w << endl;
                return 0;
            }
        }
    }
}