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
#define MOD 1000000007
using namespace std;

ll fac[100005];  //k!(mod M)
ll aa[100005]; //n!(1+1/2+..+1/k) (mod M)
ll saa[100005];

ll mpow(ll x, ll n){ //x^n(mod M)
    ll ans = 1;
    while(n != 0){
        if(n&1) ans = ans*x % MOD;
        x = x*x % MOD;
        n = n >> 1;
    }
    return ans;
}

void pre( long n )
{
    fac[0] = 1;
    long i;
    for(i=0; i<n; i++){
        fac[i+1] = fac[i]*(i+1) % MOD; // k!(mod M)
    }
    aa[0]=saa[0]=0;
    for(i=1; i<=n; i++) {
        aa[i] = fac[n] * mpow(i, MOD-2) % MOD;
        saa[i] = saa[i-1] + aa[i];
    }

    return;
}

int main(int argc, char* argv[])
{    
    long n;
    scanf("%ld", &n);

    vector<long> a(n+1);
    long i;
    for(i=1; i<=n; i++) {
        scanf("%ld", &a[i]);
    }

    pre(n);

    ll ans = 0;
    for(i=1; i<=n; i++) {
        ll tmp = (saa[i] + saa[n-i+1] - fac[n] + MOD)%MOD;
        ans = (ans + tmp * a[i]) %MOD;
    }

    printf("%lld\n", ans);
    return 0;
}
