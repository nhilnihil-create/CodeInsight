#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;


int main() {
    int n; cin >> n;
    V<ll> x(n), y(n);
    V<ll> h(n);
    for(int i = 0; i < n; i++) cin >> x[i] >> y[i] >> h[i];

    int nz = 0;
    for(int i = 0; i < n; i++){
        if(h[i]){
            nz = i;
            break;
        }
    }

    for(ll i = 0; i <= 100; i++){
        for(ll j = 0; j <= 100; j++){
            bool ok = true;
            ll H = h[nz] + abs(x[nz] - i) + abs(y[nz] - j);
            for(int k = 0; k < n; k++){
                ll tmp = max(H - abs(x[k] - i) - abs(y[k] - j), 0LL);
                if(h[k] == tmp) continue;
                else{
                    ok = false;
                    break;
                }
            }
            if(ok){
                cout << i << " " << j << " " << H << endl;
                return 0;
            }
        }
    }

    return 0;
}
