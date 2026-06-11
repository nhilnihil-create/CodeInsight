#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;
using ld = long double;
const int MOD = 1e9+7;
const ll INF = 1LL << 60;


int main() {
    ll a, b, k; cin >> a >> b >> k;
    bool flip = true;
    for(int i = 0; i < k; i++){
        if(flip){
            if(a & 1) a--;
            b += (a / 2);
            a /= 2;
        }else{
            if(b & 1) b--;
            a += (b / 2);
            b /= 2;
        }
        flip = !flip;
    }
    cout << a << ' ' << b << endl;

    return 0;
}
