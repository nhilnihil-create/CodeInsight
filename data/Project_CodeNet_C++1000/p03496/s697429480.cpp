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


int main(int argc, char* argv[])
{
    long n;
    scanf("%ld", &n);
    vector<long> a(n);
    long i;
    long min=MOD;
    long max=-MOD;
    long imin=0, imax=0;
    for(i=0; i<n; i++) {
        scanf("%ld", &a[i]);
        if(min>a[i]) {
            min=a[i]; imin=i;
        }
        if(max<a[i]) {
            max=a[i]; imax=i;
        }
    }

    if(abs(max)>=abs(min)) {
        printf("%ld\n", 2*n-2);
        for(i=0; i<n; i++) {
            if(i!=imax) {
                printf("%ld %ld\n", imax+1, i+1);
            }
        }
        for(i=0; i<n-1; i++) {
            printf("%ld %ld\n", i+1, i+2);
        }
    }
    else {
        printf("%ld\n", 2*n-2);
        for(i=0; i<n; i++) {
            if(i!=imin) {
                printf("%ld %ld\n", imin+1, i+1);
            }
        }
        for(i=n-1; i>0; i--) {
            printf("%ld %ld\n", i+1, i);
        }
    }
    
    return 0;
}
