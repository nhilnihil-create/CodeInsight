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

char str[200005];
char qq[200005][2];

int main(int argc, char* argv[])
{
    long n, q;
    scanf("%ld%ld\n", &n, &q);
    scanf("%s", str);

    long i;
    for(i=0; i<q; i++) {
        char str0[5]={0};
        scanf("%s", str0);
        qq[i][0]=str0[0];
        scanf("%s", str0);
        qq[i][1]=str0[0];
    }

    long curr0=0, curr1=0;
    {
        long r=n, l=-1;
        while( r-l>1 ) {
            long m=(l+r)/2;
            long curr=m;
            long fail=0;
            for(i=0; i<q; i++) {
                if(str[curr]==qq[i][0] && qq[i][1]=='R') {
                    curr++;
                    if(curr==n) {
                        break;
                    }
                }
                else if(str[curr]==qq[i][0] && qq[i][1]=='L') {
                    curr--;
                    if(curr==-1) {
                        fail=1;
                        break;
                    }
                }
            }
            if(i==q) {
                fail=1;
            }
            if( fail ) {
                l=m;
            }
            else {
                r=m;
            }
        }
        curr0 = r;
    }

    {
        long r=n, l=-1;
        while( r-l>1 ) {
            long m=(l+r)/2;
            long curr=m;
            long fail=0;
            for(i=0; i<q; i++) {
                if(str[curr]==qq[i][0] && qq[i][1]=='R') {
                    curr++;
                    if(curr==n) {
                        fail=1;
                        break;
                    }
                }
                else if(str[curr]==qq[i][0] && qq[i][1]=='L') {
                    curr--;
                    if(curr==-1) {
                        break;
                    }
                }
            }
            if(i==q) {
                fail=1;
            }
            if( fail ) {
                r=m;
            }
            else {
                l=m;
            }
        }
        curr1 = l;
    }

    printf("%ld\n", MAX(curr0-curr1-1, 0));
    return 0;
}
