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
const long long MOD = 1000000007;
using namespace std;


int main(int argc, char* argv[])
{
    int n, k;
    scanf("%d%d", &n, &k);
    k++;

    vector<int> a(n),b(n);
    int i,j;
    for(i=0; i<n; i++) {
        scanf("%d%d", &a[i], &b[i]);
    }

    ll ans=-LINF;
    vector<int> bad(n,0);
    for(i=31; i>=0; i--) {
        ll sum=0;
        if(k & (1<<i)) {
            for(j=0; j<n; j++) {
                if(bad[j]==0) {
                    if(!(a[j] & (1<<i))) sum+=b[j];
                }
            }
        }
        else {
            for(j=0; j<n; j++) {
                if(bad[j]==0) {
                    if(a[j] & (1<<i)) bad[j]=1;
                }
            }
        }
        //printf("%lld\n", sum);
        ans = MAX(ans,sum);
    }
    printf("%lld\n", ans);

    return 0;
}

