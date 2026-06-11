#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

#define X first
#define Y second
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair <int, int> pii;

const int INF=0x3f3f3f3f;
const ll MOD=998244353;
const int N=3e5+5;

ll n, A, B, k;
ll fakt[N];

ll add(ll a, ll b) {
    return (a+b)%MOD;
}

ll mul(ll a, ll b) {
    return (a*b)%MOD;
}

ll pot(ll base, ll exponent) {
    ll result = 1;
    while (exponent>0) {
        if (exponent & 1)
            result=mul(result, base);
        exponent=exponent/2;
        base=mul(base, base);
    }
    return result;
}

ll povrh(ll n, ll k) {
    if (k==0) return 1LL;
    return mul(fakt[n], pot(mul(fakt[n-k], fakt[k]), MOD-2));
}

int main() {
    scanf("%lld %lld %lld %lld", &n, &A, &B, &k);
    fakt[0]=1;
    for (int i=1; i<=n+2; ++i) fakt[i]=mul(fakt[i-1], (ll)i);
    ll sol=0;
    for (ll a=0; a<=n; ++a) {
        if ((k-a*A)%B || k<a*A) continue;
        ll b=(k-a*A)/B;
        if (b<0) continue;
        if (b>n) continue;
        sol=add(sol, mul(povrh(n, (ll)a), povrh(n, (ll)b)));
    }
    printf("%lld\n", sol);
    return 0;
}
