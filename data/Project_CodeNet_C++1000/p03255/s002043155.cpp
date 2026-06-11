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

long n;
ll   x;
vector<ll> a;

ll solve( long k )
{
    ll  ans = (n + k) * x;
    long i;
    for(i=1; i<=n; i++) {
        long curr = n-i;
        long m = ((i-1)/k+1);
        ans += a[curr] * (m>1? 2*m+1: 5);
    }
    return ans;
}

int main(int argc, char* argv[])
{
    scanf("%ld%lld", &n, &x);

    a.resize(n);
    long i;
    for(i=0; i<n; i++) {
        scanf("%lld", &a[i]);
    }
   
    long kk=1, mm=n;
    ll   kk_val=solve(kk);
    ll   mm_val=solve(mm);
    while(mm-kk>2) {
        long dif = (mm-kk)/3;
        long m0 = kk + dif;
        long m1 = m0 + dif;
        ll   m0_val = solve(m0);
        ll   m1_val = solve(m1);
        if(m0_val > m1_val) {
            kk = m0;  kk_val = m0_val;
        }
        else {
            mm = m1;  mm_val = m1_val;
        }
    }

    ll  min = MIN(kk_val, mm_val);
    for(i=kk+1; i<mm; i++) {
        ll val = solve(i);
        min = MIN(min, val);
    }
    printf("%lld\n", min);

    return 0;
}
