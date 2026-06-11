#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll n;
    cin >> n;
    for(ll i = 1; i <= 3500; i++){
        for(ll j = 1; j <= 3500; j++){
            if(4 * i * j - n * i - n * j == 0)
            continue;
            ll w = (n *i * j) / (4 * i * j - n * i - n * j);
            if(w > 0 && (n *i * j) % (4 * i * j - n * i - n * j) == 0){
                cout << j << " " << i << " " << w << endl;
                return 0;
            }
            
           }
        }
    }
