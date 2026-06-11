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
    int n,a,b;
    scanf("%d%d%d", &n, &a, &b);

    if(n>(ll)a*b || n<a+b-1) {
        printf("-1\n"); return 0;
    }
    if(b==1) {
        int i;
        for(i=0; i<n; i++) {
            printf("%d ", i+1);
        }
        printf("\n");
        return 0;
    }

    int m=n-a;
    int q=m/(b-1);
    int r=m%(b-1);
    vector<ll> aa(a), sa(a+1);
    int i;
    for(i=0; i<a; i++) {
        if(i<q) aa[i]=b;
        else if(i==q) aa[i]=1+r;
        else aa[i]=1;
    }
    for(i=0; i<a; i++) {
        sa[i+1]=sa[i]+aa[i];
    }
    for(i=0; i<a; i++) {
        int curr=sa[i+1];
        int j;
        for(j=0; j<aa[i]; j++) {
            printf("%d ", curr);
            curr--;
        }
    }
    printf("\n");

    return 0;
}