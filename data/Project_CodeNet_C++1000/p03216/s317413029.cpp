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

char str[1000005];

void solve()
{
    int n;
    scanf("%d%s", &n, str);
    int Q;
    scanf("%d", &Q);
    int q;
    for(q=0; q<Q; q++) {
        int K;
        scanf("%d", &K);
        ll cnt0=0, cnt1=0, cnt01=0;
        ll ans=0;
        int i;
        for(i=0; i<n; i++) {
            if(i-K>=0) {
                if(str[i-K]=='D') {
                    cnt0--;
                    cnt01-=cnt1;
                }
                if(str[i-K]=='M') {
                    cnt1--;
                }
            }

            if(str[i]=='C') {
                ans+=cnt01;
            }
            if(str[i]=='M') {
                cnt1++;
                cnt01+=cnt0;
            }
            if(str[i]=='D') {
                cnt0++;
            }
        }
        printf("%lld\n", ans);
    }
    
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
