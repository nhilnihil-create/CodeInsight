#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <tuple>
#include <cassert>

using namespace std;

#define all(c) (c).begin(), (c).end()
#define iter(c) __typeof((c).begin())
#define cpresent(c, e) (find(all(c), (e)) != (c).end())
#define tr(c, i) for (iter(c) i = (c).begin(); i != (c).end(); ++i)
#define pb(e) push_back(e)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define mp(a,b) make_pair((a), (b))
#define mt(a,b,c) make_tuple((a),(b),(c))
#define MOD 998244353
typedef long long ll;
long long modinv(long long a, long long m = MOD) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}
vector<ll> fact(400005);
long long comb(long long n, long long r, long long m = MOD){
    if(n<r) return 0;
    if(r<0) return 0;
    return (((fact[n] * modinv(fact[n-r]))%m) * modinv(fact[r])) % m;
}

int main(){
    fact[0] = 1;
    FOR(i,1,400002) fact[i]  = (fact[i-1] * i) % MOD;
    ll n,a,b,k; cin >> n >> a >> b >> k;
    ll ans = 0;
    rep(i,n+1){
        if((k - i*a) % b == 0){
            ll y = (k - i*a) / b;
            ans += (comb(n,i) * comb(n, y)) % MOD;
            ans %= MOD;
        }
    }
    cout << ans << endl;
    return 0;
}