#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
using ull = unsigned long long int;
using P = pair<int, int>;
using P3 = pair<P,int>;
using PP = pair<P, P>;
constexpr int INF = 1 << 30;
constexpr ll MOD = ll(1e9)+7;
constexpr int di[] = {0, 1, 0, -1};
constexpr int dj[] = {1, 0, -1, 0};
constexpr int di8[] = {0, 1, 1, 1, 0, -1, -1, -1};
constexpr int dj8[] = {1, 1, 0, -1, -1, -1, 0, 1};
constexpr double EPS = 1e-9;

ll power(ll x, ll n){
    ll res = 1;
    x %= MOD;
    while(n>0){
        if(n&1) res = res*x%MOD;
        x = x*x%MOD;
        n >>= 1;
    }
    return res;
}

ll mod_inv(ll x){
    return power(x, MOD-2);
}

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n), s(n+1);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=n;i++){
        s[i] = (s[i-1]+mod_inv(i))%MOD;
    }
    ll ans = 0;
    for(int i=0;i<n;i++){
        ans += (s[i+1]+s[n-i]-1)*a[i]%MOD;
    }
    for(int i=2;i<=n;i++){
        ans = ans*i%MOD;
    }
    cout << ans << endl;
    return 0;
}