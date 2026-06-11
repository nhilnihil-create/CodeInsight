#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n,y;
    cin >> n >> y;
    bool fin = false;
    
    for (ll i = 0; i <= n; i++){
        for (ll j = 0; j <= (n-i); j++){
            ll k = n-(i+j);
            if ((10000*i + 5000*j + 1000*k) == y){
                cout << i << " " << j << " " << k << "\n";
                fin = true;
                break;
            }
        }
        if (fin){
            break;
        }
    }

    if (!fin){
        cout << "-1 -1 -1" << "\n";
    }
}