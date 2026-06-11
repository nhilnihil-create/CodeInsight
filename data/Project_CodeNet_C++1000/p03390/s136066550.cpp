
#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>

using namespace std;

#define int_ int64_t
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned ll
#define db double
#define lb long double
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define PII pair<int, int>

ll n,a,b;

ll solve(ll a,ll b) {
    ll c=a*b;
    if (c<=3) {
        if (c==1||c==2) return 0;
        else return 1;
    } else {
        ll r=sqrt(c);
        if (r*r==c) {
            if (r==a) return 2*r-2;
            else return 2*r-3;
        } else if (r*r<c&&c<=r*(r+1)) {
            return 2*r-2;
        } else {
            return 2*r-1;
        }
    }
}

int main()
{
    scanf("%lld",&n);
    for (ll i=1;i<=n;i++) {
        scanf("%lld%lld",&a,&b);
        printf("%lld\n",solve(a,b));
    }
}