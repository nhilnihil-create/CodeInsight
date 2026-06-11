#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define V vector
#define P pair
typedef long long ll;

int main() {
    ll n; cin >> n;
    V<ll> x(n), y(n), h(n);
    for(ll i = 0; i < n; i++){
        cin >> x[i] >> y[i] >> h[i];
    }

    ll s;
    for(ll i = 0; i < n; i++){
        if(h[i]){
            s = i;
            break;
        }
    }

    for(ll i = 0; i <= 100; i++){
        for(ll j = 0; j <= 100; j++){
            bool flag = true;
            ll H = max(h[s] + abs(x[s] - i) + abs(y[s] - j), 0LL);
            for(ll k = 0; k < n; k++){
                ll tmp = max(H - abs(x[k] - i) - abs(y[k] - j), 0LL);
                if(h[k] != tmp){
                    flag = false;
                    break;
                }
            }
            if(flag){
                cout << i << " " << j << " " << H << endl;
            }
        }
    }
}
