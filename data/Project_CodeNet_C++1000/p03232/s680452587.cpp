#include "bits/stdc++.h"
 
typedef long long ll;
#define int ll
#define fi first
#define se second
#define SORT(a) sort(a.begin(),a.end())
#define REP(i,n) for(int i = 0;i < (n) ; i++) 
#define MP(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define INF LLONG_MAX/2

using namespace std;

int MOD = 1000000007;

ll bitpow(ll x,ll n){
    ll ans = 1;
    while(n > 0){
        if(n%2 == 1) ans = ans * x % MOD;
        x = x * x %MOD;
        n = n >> 1;
    }
    return ans;
}

//高速nCk
// int MOD = 1000000007;
int N = 100000;
int fac[100001];
int inv[100001];

ll COM(ll n,ll k){
    return fac[n]*inv[k]%MOD*inv[n-k]%MOD;
}

signed main(){
    
    int n;
    cin >> n;

    fac[0] = 1;
    inv[0] = 1;
    for(int i = 1;i <= N;i++){
        fac[i] = fac[i-1]*i%MOD;
        inv[i] = bitpow(i,MOD-2)%MOD;
    }

    vector<int> a;
    REP(i,n){
        int x;
        cin >> x;
        a.pb(x);
    }

    int gsum[100001] = {0};
    for(int i = 1;i <= n;i++){
        gsum[i] = (gsum[i-1] + inv[i])%MOD;
    }

    int A[N+1];
    for(int i = 1;i <= n;i++){
        A[i] = (gsum[1+abs(1-i)] + gsum[1+abs(n-i)] - 1 + MOD)%MOD*fac[n]%MOD;
    }

    int ans = 0;
    REP(i,n){
        ans += a[i]*A[i+1];
        ans %= MOD;
    }



    cout << ans << endl;

    return 0;
}
// g++ -std=c++14 code1.cpp
// rm -r -f test;oj dl 