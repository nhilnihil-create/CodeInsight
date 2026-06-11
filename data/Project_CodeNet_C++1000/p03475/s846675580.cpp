#include <iostream>
#include <string>
#include <algorithm>
#include <cassert>
#include <set>
#include <vector>
#include <cmath>
#include <bitset>
#include <functional>
#include <limits>
#include <map>
using namespace std;

typedef long long ll;
#define rep1(i, n) for(ll i = 1; i <=(ll)(n); i++)
#define rep0(i, n) for(ll i = 0; i <=(ll)(n); i++)

ll pow(ll a, ll n) { //compute a^n with o(logn)
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a;
        a = a * a;
        n >>= 1;
    }
    return res;
}

ll pow(ll a, ll n, ll mod) { //compute a^n (mod mod) with o(logn)
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main(){
    ll n;
    cin >> n;
    ll c[n], s[n], f[n];
    rep1(i,n-1){
        cin >> c[i]>>s[i] >> f[i];
    }
    rep1(i,n-1){
        double l = 0;
        for(ll j = i;j < n-1; j++){
            double tmp = s[j] + c[j] +l*f[j] - s[j+1];
            if(tmp < 0){
                l = 0;
            }else{            
                l = ceil(tmp/f[j+1]);
            }
        }
        cout << s[n-1] + l*f[n-1] + c[n-1] << endl;
    }
    cout << 0 << endl;
    return 0;
}