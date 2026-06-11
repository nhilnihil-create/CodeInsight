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

    long curr=n;
    for(i=q-1; i>=0; i--) {
        if(curr>0 && str[curr-1]==qq[i][0] && qq[i][1]=='R') {
            curr--;
        }
        else if(str[curr]==qq[i][0] && qq[i][1]=='L') {
            curr++;
        }
    }

    long curr1=-1;
    for(i=q-1; i>=0; i--) {
        if(curr1==n-1) break;
        if(curr1<n-1 && str[curr1+1]==qq[i][0] && qq[i][1]=='L') {
            curr1++;
        }
        else if(str[curr1]==qq[i][0] && qq[i][1]=='R') {
            curr1--;
        }
    }
    //printf("%ld, %ld\n", curr, curr1);
    printf("%ld\n", MAX(curr-curr1-1, 0));
    return 0;
}
