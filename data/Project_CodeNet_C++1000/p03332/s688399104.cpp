#include <stdio.h>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <list>
#include <iterator>
#pragma warning(disable:4996)
 
typedef long long ll;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF 9223300000000000000
#define INF 2140000000
//#define MOD 1000000007
#define MOD 998244353
using namespace std;

vector<ll> fac(300001); //n!(mod M)
vector<ll> ifac(300001); //k!^{M-2} (mod M)

ll mpow(ll x, ll n){ //x^n(mod M)
    ll ans = 1;
    while(n != 0){
        if(n&1) ans = ans*x % MOD;
        x = x*x % MOD;
        n = n >> 1;
    }
    return ans;
}

ll comb(long a, long b){     // C(a,b) = a! * b!^(M-2) * (a-b)^(M-2)
    if(a == 0 && b == 0)return 1;
    if(a < b || a < 0)return 0;
    ll tmp = ifac[a-b]* ifac[b] % MOD;
    return tmp * fac[a] % MOD;
}

void pre_comb()
{
    fac[0] = 1;
    ifac[0] = 1;
    for(long i = 0; i<300000; i++){
        fac[i+1] = fac[i]*(i+1) % MOD; // n!(mod M)
        ifac[i+1] = ifac[i]*mpow(i+1, MOD-2) % MOD; // k!^{M-2} (mod M)
    }
    return;
}

int main(int argc, char* argv[])
{
    long n, a, b;
    ll   k;
    scanf("%ld%ld%ld%lld", &n, &a, &b, &k);

    pre_comb();

    ll ans=0;
    long i;
    for(i=0; i<=k/a && i<=n; i++) {
        if( (k-i*a)%b==0 ) {
            ll j = (k-i*a)/b;
            if(j<=n) {
                ans = (ans + comb(n, i) * comb(n, (long)j) %MOD) %MOD;
            }
        }
    }

    printf("%lld\n", ans);

    return 0;
}

