#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<functional>
#include<cstdio>
#include<cstdlib>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
#define MOD 1000000007
//#define MOD 998244353
#define LINF (long long)4e18
#define jck 3.141592
#define PI acos(-1.0);

const double EPS = 1e-10;

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;


struct Combination{
    vector<long long> _fac,_finv,_inv;
    const int m = MOD;

    Combination(int sz) : _fac(sz),_finv(sz),_inv(sz){
        _fac[0] = _fac[1] = 1;
        _finv[0] = _finv[1] = 1;
        _inv[1] = 1;
        for(int i = 2; i <= sz; i++){
            _fac[i] = _fac[i-1]*i%m;
            _inv[i] = m-_inv[m%i]*(m/i)%m;
            _finv[i] = _finv[i-1]*_inv[i]%m;
        }
    }

    inline long long fac(int n){return _fac[n];}
    inline long long inv(int n){return _inv[n];}
    inline long long finv(int n){return _finv[n];}

    long long comb(int n,int k){
        if(n < k) return 0;
        if(n < 0 || k < 0) return 0;
        return _fac[n]*(_finv[k]*_finv[n-k]%m)%m;
    }
};

int main(){
    int N; cin >> N;
    vector<int> A(N);
    rep(i,N) cin >> A[i];
    vector<ll> sum(N+1);
    rep(i,N){
        sum[i+1] = sum[i]+A[i];
        sum[i+1] %= MOD;
    }
    vector<ll> sum2(N+2);
    rep(i,N+1){
        sum2[i+1] = sum2[i]+sum[i];
        sum2[i+1] %= MOD;
    }
    ll ans = 0;
    Combination C(200000);
    repr(i,1,N+1){
        if(i == N){
            ans += sum[N];
            ans %= MOD;
            continue;
        }
        ans += sum[i]*C.inv(i+1)%MOD;
        ans %= MOD;
        ans += (sum[N]-sum[N-i]+MOD)%MOD*C.inv(i+1)%MOD;
        ans %= MOD;
        if(i+2 <= N){
            ll now = 0;
            now += (sum2[N]-sum2[i+1]+MOD)%MOD;
            now -= (sum2[N-i]-sum2[1]+MOD)%MOD;
            if(now < 0) now += MOD;
            ans += now*2%MOD*C.inv(i+2)%MOD*C.inv(i+1)%MOD;
            ans %= MOD;
        }
    }
    ans *= C.fac(N);
    ans %= MOD;
    cout << ans << endl;
}

