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

long dbg_print = 0;

ll calc( const char* str, long n0, const char* str0, long n1, const char* str1 )
{
    if ( dbg_print ) {
        printf("(%s)(%s)(%s) ", str, str0, str1);
    }

    ll dp[20][20]={0};

    long i,j;
    for(i=0; i<=n0; i++) {
        for(j=0; j<=n1; j++) {
            if(i==0 && j==0) {
                dp[i][j] = 1;
            }
            else {
                if(i>0 && str[i+j-1]==str0[i-1]) {
                    dp[i][j] += dp[i-1][j];
                }
                if(j>0 && str[i+j-1]==str1[j-1]) {
                    dp[i][j] += dp[i][j-1];
                }
            }
        }
    }
    if ( dbg_print ) {
        printf("%lld\n", dp[n0][n1]);
    }

    return dp[n0][n1];
}

int main(int argc, char* argv[])
{
    scanf("%ld", &n);

    char str[40]={0};
    scanf("%s", str);

    {
        char str0[20]={0};
        char str1[20]={0};
        strncpy( str0, str+0, n);
        sort( str0+0, str0+n );
        strncpy( str1, str+n, n);
        sort( str1+0, str1+n );
        if( strcmp( str0, str1 ) != 0 ) {
            printf("0\n");
            return 0;        
        }
    }

    char strrev[40]={0};
    long i;
    for(i=0; i<n; i++) {
        strrev[i] = str[2*n-1-i];
    }

    ll ans = 0;

    char str0[40]={0};
    char str1[40]={0};
    long bit, k;
    for(bit=0; bit<(1<<n); bit++) {
        long cnt0=0, cnt1=0;
        for(k=0; k<n; k++) {
            if(bit & (1<<k)) {
                str0[cnt0]=str[k];
                cnt0++;
            }
            else {
                str1[cnt1]=str[k];
                cnt1++;
            }
        }
        str0[cnt0]=0;
        str1[cnt1]=0;

        ans += calc( strrev, cnt0, str0, cnt1, str1 );
    }

    printf("%lld\n", ans);

    return 0;
}

