#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;


int main(){
    ll n;   cin >> n;

    for(ll i=1; i<=3500; i++){
        for(ll j=1; j<=3500; j++){
            ll c=n*i*j, p=4*i*j-n*(i+j);
            if(0<p && c%p==0){
                ll w = c/p;
                if(w<=0 || 3500<w) continue;
                cout << i << ' ' << j << ' ' << w << endl;
                return 0;

            }

        }
    }
}