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

# define n 100000

int main(){
    ll q;;
    cin >> q;
    bool isPrime[n+1];
    rep1(i,n){
        if(i % 2 == 0) isPrime[i] = false;
        else isPrime[i] = true;
        if(i == 1) isPrime[i] = false;
        if(i == 2) isPrime[i] = true;
    }

    ll sum[n+1] = {0};
    ll tmp_sum = 0;
    for(ll i = 3; i <= 1e5; i += 2){
        if(isPrime[i] == true){
            for(ll j = 2; j*i <= 1e5; j++) isPrime[j*i] = false;
            if(isPrime[(i+1)/2] == true){
                tmp_sum++;
            }
        }
        sum[i] = tmp_sum;
    }

    rep1(i,q){
        ll l,r;
        cin >> l >> r;
        if(l == 1) cout << sum[r] << endl; 
        else cout << sum[r] - sum[l-2] << endl;
    }
    return 0;
}