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
 
char str[100005];
ll a[100005][4];

int main(int argc, char* argv[])
{
    scanf("%s", str);
    int n=strlen(str);
    a[0][0]=1;
    int i;
    for(i=0; i<n; i++) {
        a[i+1][0]=a[i][0]*(str[i]=='?'?3:1)%MOD;
        a[i+1][1]=a[i][1]*(str[i]=='?'?3:1)%MOD;
        a[i+1][2]=a[i][2]*(str[i]=='?'?3:1)%MOD;
        a[i+1][3]=a[i][3]*(str[i]=='?'?3:1)%MOD;

        if(str[i]=='A' || str[i]=='?') {
            a[i+1][1]=(a[i+1][1]+a[i][0])%MOD;
        }
        if(str[i]=='B' || str[i]=='?') {
            a[i+1][2]=(a[i+1][2]+a[i][1])%MOD;
        }
        if(str[i]=='C' || str[i]=='?') {
            a[i+1][3]=(a[i+1][3]+a[i][2])%MOD;
        }
    }
    printf("%lld\n", a[n][3]);

    return 0;
}