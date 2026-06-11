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
#include <stack>
#include <list>
#include <iterator>
#include <assert.h>
#pragma warning(disable:4996) 
 
typedef long long ll;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF 9223300000000000000
#define INF 2140000000
const long long MOD = 1000000007;
//const long long MOD = 998244353;

using namespace std;

ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b,a%b);
}
 
ll lcm(ll a, ll b) {
    ll g = gcd(a,b);
    return a / g * b;   // Be careful not to overflow
}


vector<int> pp;
void preparePrime( int maxp )
{
    int i;
    vector<int> a(maxp+1);
    for(i=2; i<=maxp; i++) {
        int k=i+i;
        while(k<=maxp) {
            a[k]=1;
            k+=i;
        }
    }
    for(i=2; i<=maxp; i++) {
        if(a[i]==0) pp.push_back( i );
    }
    return;
}

void solve()
{
    int n;
    scanf("%d", &n);
    preparePrime(1000000);
    vector<int> z;
    int i;
    for (i = 1; i < (int)pp.size(); i++) {
        if (pp[i] % 5 == 1) {
            z.push_back(pp[i]);
            if (z.size() == n) break;
        }
    }
    for (i = 0; i < n; i++) {
        printf("%d", z[i]);
        if (i < n - 1) printf(" ");
    }
    printf("\n");
    return;
}

int main(int argc, char* argv[])
{
#if 1
    solve();
#else
    int T; scanf("%d", &T);
    while(T--) {
        solve();
    }
#endif
    return 0;
}
