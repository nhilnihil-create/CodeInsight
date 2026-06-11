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
    map<ll,ll> cnt;
    vector<ll> a(n+1);
    rep0(i,n-1) cin >> a[i];    
    vector<ll> sum(n+1, 0);
    rep0(i,n-1) sum[i+1] = sum[i] + a[i];
    rep0(i,n) cnt[sum[i]]++;

    ll combination_num = 0;
    for(auto it: cnt){
        ll num = it.second;
        combination_num += num*(num-1)/2;
    }
    cout << combination_num << endl;
    return 0;
}