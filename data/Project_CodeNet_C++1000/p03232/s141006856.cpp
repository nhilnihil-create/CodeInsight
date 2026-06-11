#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <typeinfo>
#include <numeric>
#include <functional>
#include <unordered_map>
#include <bitset>
#include <stack>


using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll INF = 1e16;
const ll MOD = 1e9 + 7;

#define REP(i, n) for(ll i = 0; i < n; i++)
#define Yes(condition) if(condition){ cout << "Yes" << '\n'; }else{ cout << "No" << '\n'; }
#define YES(condition) if(condition){ cout << "YES" << '\n'; }else{ cout << "NO" << '\n'; }
#define yes(condition) if(condition){ cout << "yes" << '\n'; }else{ cout << "no" << '\n'; }





long long POW(long long n, long long m, long long p){
    if(m == 0){
        return 1;
    }
    if(m % 2 == 0){
        long long tmp = POW(n, m / 2, p) % p;
        return tmp * tmp % p;
    }
    else{
        return n * POW(n, m - 1, p) % p;
    }
}

// a^(p - 1 - x) ≡ a^(-x) (mod p)
long long Fermat(long long a, long long x, long long p){
    return POW(a, p - 1 - x, p);
}

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n + 1);
    REP(i, n){
        cin >> a[i + 1];
    }
    vector<ll> h(n + 1);
    for(ll i = 1; i <= n; i++){
        h[i] = h[i - 1] + Fermat(i, 1, MOD);
        h[i] %= MOD;
    }
    
    ll ans = 0;
    for(ll i = 1; i <= n; i++){
        ans += a[i] * ((h[i] + h[n + 1 - i] - 1) % MOD);
        ans %= MOD;
    }
    
    ll k = 1;
    for(ll i = 2; i <= n; i++){
        k *= i;
        k %= MOD;
    }
    
    ans *= k;
    ans %= MOD;
    
    cout << ans << endl;
}