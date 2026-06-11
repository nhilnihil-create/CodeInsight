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
//const long long MOD = 1000000007;
const long long MOD = 998244353;
using namespace std;

char str[10];

int main(int argc, char* argv[])
{
    int n;
    scanf("%d", &n);

    printf("0\n"); fflush(stdout);
    scanf("%s", str);
    if(strcmp(str, "Vacant")==0) {
        return 0;
    }
    int flag0 = (strcmp(str, "Male")==0)? 0: 1;
    int l=0, r=n;
    while(r-l>1) {
        int m=(l+r)/2;
        printf("%d\n", m); fflush(stdout);
        scanf("%s", str);
        if(strcmp(str, "Vacant")==0) {
            return 0;
        }
        int flagtmp = (strcmp(str, "Male")==0)? 0: 1;
        if((m-l+flag0+flagtmp)%2) {
            r=m;
        }
        else {
            l=m;
            flag0=flagtmp;
        }
    }

    return 0;
}
