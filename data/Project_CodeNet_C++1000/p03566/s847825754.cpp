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
#include <iterator>
#pragma warning(disable:4996)
 
typedef long long ll;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define MOD 1000000007
using namespace std;


long t[105];
long v[105];
long h[105];
long st[105];

int main(int argc, char* argv[])
{
    long n;
    scanf("%ld", &n);

    long i;
    for(i=0; i<n; i++) {
        scanf("%ld", &t[i]);
    }
    for(i=0; i<n; i++) {
        scanf("%ld", &v[i]);
    }
    st[0]=0;
    for(i=1; i<=n; i++) {
        st[i]=st[i-1]+t[i-1];
    }

    h[0]=h[n]=0;
    for(i=1; i<n; i++) {
        h[i] = MIN(v[i-1], v[i]);
    }

    long j;
    for(i=1; i<n; i++) {
        for(j=0; j<=n; j++) {
            h[i] = MIN(h[i], h[j]+abs(st[j]-st[i]));
        }
    }

    double ss = 0.0;
    for(i=0; i<n; i++) {
        double tmp=0;
        double tmp2 = (double)(t[i]+h[i]+h[i+1])/2.0;
        if( v[i] >tmp2 ) {
            tmp= (double)t[i] * tmp2 - (double)(tmp2-h[i])*(tmp2-h[i])*0.5 - (double)(tmp2-h[i+1])*(tmp2-h[i+1])*0.5;
        }
        else {
            tmp= (double)t[i] * v[i] - (double)(v[i]-h[i])*(v[i]-h[i])*0.5 - (double)(v[i]-h[i+1])*(v[i]-h[i+1])*0.5;
        }
        ss += tmp;
    }

    printf("%.8lf\n", ss);

    return 0;
}
