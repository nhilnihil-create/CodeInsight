#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <string>
#include <set>
#include <bitset>
#include <unordered_map>
#include <cmath>
#include <functional>
#include <map>
#include <cstdlib>
#include <stack>

using namespace std;
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
template <class T>
using Vvec = vector<vector<T> >;
using Graph = Vvec<int>;
constexpr ll MOD = 1e9+7;

template <class T>
void debug(T& v)
{
    for(auto& x: v) cout << x << " ";
    cout << endl;
}

// ax + by = d
template <class T>
T ext_gcd(T a, T b, T& x, T& y)
{
    x = 1; y = 0;
    T xb = 0, yb = 1;
    T xr, yr, q, r;
    while(b != 0){
        q = a/b;
        xr = x - q * xb;
        yr = y - q * yb;
        r = a - q * b;

        x = xb;
        y = yb;
        a = b;
        xb = xr;
        yb = yr;
        b = r;
    }
    return a;
}

ll modinv(ll a){
    ll x, y;
    ext_gcd(a, MOD, x, y);
    x = (x < 0) ? (MOD - (-x) % MOD) : x % MOD;
    if(x >= MOD) x -= MOD;
    return x;
}

int main()
{
    int N;
    cin >> N;
    vector<ll> A(N);
    for(auto& x: A) cin >> x;

    vector<ll> inv(N+2);
    for(int i=1; i<=N+1; i++) inv[i] = modinv(i);

    ll p=0, ans=0;
    for(int i=1; i<=N; i++){
        p += inv[i]; p %= MOD;
    } 
    for(int i=0; i<N; i++){
        ans += p * A[i];
        ans %= MOD;
        p += inv[i+2] - inv[N-i];
        if(p<0) p += MOD;
        p %= MOD;
    }

    for(int i=1; i<=N; i++){
        ans *= i;
        ans %= MOD;
    }

    cout << ans << endl;
}