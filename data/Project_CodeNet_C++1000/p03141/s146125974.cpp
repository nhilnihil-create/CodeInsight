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
 
int main(int argc, char* argv[])
{    
    int n;
    scanf("%d", &n);
    vector<ll> z(n);
    int i;
    ll sum=0;
    for(i=0; i<n; i++) {
        int a,b;
        scanf("%d%d", &a, &b);
        z[i]=a+b;
        sum-=b;
    }
    sort(z.rbegin(), z.rend());

    for(i=0; i<n; i++) {
        if(i%2==0) {
            sum+=z[i];
        }
    }
    printf("%lld\n", sum);

    return 0;
}