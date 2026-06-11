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
#include <bitset>
#pragma warning(disable:4996) 
 
typedef long long ll;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF 9223300000000000000
#define INF 2140000000
const long long MOD = 1000000007;
using namespace std;

char str[1000005];

int main(int argc, char* argv[])
{
    int n,Q;
    scanf("%d%s%d", &n, str, &Q);

    int q;
    for(q=0; q<Q; q++) {
        int K;
        scanf("%d", &K);

        ll ans=0;
        int cnt0=0, cnt1=0;
        ll cnt01=0;

        int i;
        for(i=0; i<n; i++) {
            if(i>=K) {
                if(str[i-K]=='D') {
                    cnt0--;
                    cnt01 -= cnt1;
                }
                else if(str[i-K]=='M') {
                    cnt1--;
                }
            }

            if(str[i]=='D') {
                cnt0++;
            }
            else if(str[i]=='M') {
                cnt1++;
                cnt01+=cnt0;
            }
            else if(str[i]=='C') {
                ans+=cnt01;
            }
        }
        printf("%lld\n", ans);
    }
    
    return 0;
}
