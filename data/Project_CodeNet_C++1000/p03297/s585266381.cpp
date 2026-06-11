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

ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b,a%b);
}

int main(int argc, char* argv[])
{
    long n;
    scanf("%ld", &n);

    vector<long> ans(n);
    long i;
    for(i=0; i<n; i++) {
        ll a, b, c, d;
        scanf("%lld%lld%lld%lld", &a, &b, &c, &d);

        if(a<b || d<b) {
            
        }
        else if (d==b) {
            ans[i] = (a%b <= c? 1: 0);
        }
        else {
            ll x = gcd(d, b);
            ans[i] = (b - x + (a % x) <= c? 1: 0);
        }
    }

    for(i=0; i<n; i++) {
        if(ans[i]) printf("Yes\n");
        else       printf("No\n");
    }

    return 0;
}

