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

ll aa[10005];

int main(int argc, char* argv[])
{
    char str[100005]={0};
    scanf("%s", str);
    
    long len=strlen(str);

    long i;
    if(len%2==1) {
        char tmp = str[(len-1)/2];
        long curr=(len-1)/2;
        for(i=1; i<=(len-1)/2; i++) {
            if(str[curr-i]!=tmp) break;
            if(str[curr+i]!=tmp) break;
        }
        printf("%ld\n", (len-1)/2+i);
    }
    else {
        char tmp = str[len/2];
        if(tmp!=str[len/2-1]) {
            printf("%ld\n", len/2);
            return 0;
        }
        long curr=len/2-1;
        for(i=1; i<=(len/2-1); i++) {
            if(str[curr-i]!=tmp) break;
            if(str[curr+1+i]!=tmp) break;
        }
        printf("%ld\n", len/2+i);
    }

    return 0;
}
