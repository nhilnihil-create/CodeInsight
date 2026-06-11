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


int main(int argc, char* argv[])
{
    char str[55]={0};
    scanf("%s", str);
    int n=strlen(str);

    int  cnt0[6]={1,0,0,1,1,1};
    int  cnt[55]={0};
    char str2[55]={0};
    int curr=0;
    int i;
    for(i=0; i<n; i++) {
        if(str[i]=='A') {
            cnt[curr]++;
        }
        else {
            str2[curr]=str[i];
            curr++;
        }
    }
    if(curr==5 && strcmp(str2, "KIHBR")==0) {
        for(i=0; i<6; i++) {
            if(cnt[i]>cnt0[i]) {
                printf("NO\n"); return 0;
            }
        }
        printf("YES\n"); return 0;
    }
    printf("NO\n");

    return 0;
}