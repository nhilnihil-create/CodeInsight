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
#include <assert.h>
#pragma warning(disable:4996)
 
typedef long long ll;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF 9223300000000000000
#define INF 2140000000
#define MOD 1000000007
using namespace std;


int main(int argc, char* argv[])
{
    long n;
    ll a, b;
    scanf("%ld%lld%lld", &n, &a, &b);

    vector<long> p(n+2);
    long i;
    p[0]=0;
    for(i=0; i<n; i++) {
        scanf("%ld", &p[i+1]);
    }
    p[n+1]=n+1;

    vector<ll> dp(n+2, LINF);
    long j;
    dp[0]=0;
    for(i=1; i<=n+1; i++) {
        ll cst = 0;
        for(j=i-1; j>=0; j--) {
            if(p[j] < p[i]) {
                dp[i] = MIN(dp[i], dp[j] + cst);
                cst += b;
            }
            else {
                cst += a;
            }
        }
    }    

    printf("%lld\n", dp[n+1]);
    return 0;
}
