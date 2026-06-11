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
 
char str0[105];
char str1[105];
char str2[105];
 
int main(int argc, char* argv[])
{    
    int n;
    scanf("%d%s%s%s", &n, str0, str1, str2);
    int i;
    int cnt=0;
    for(i=0; i<n; i++) {
        if(str0[i]==str1[i] && str1[i]==str2[i]) {
            ;
        }
        else if(str0[i]==str1[i] || str1[i]==str2[i] || str2[i]==str0[i]) {
            cnt++;
        }
        else {
            cnt+=2;
        }
    }
    printf("%d\n", cnt);

    return 0;
}