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
#include <assert.h>
#pragma warning(disable:4996) 

typedef long long ll;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF 9223300000000000000
#define INF 2140000000
const long long MOD = 1000000007;
using namespace std;

char str[200005];

int main(int argc, char* argv[])
{
    int n,q;
    scanf("%d%d", &n, &q);
    scanf("%s", str);

    vector<char> str0, str1;
    int i;
    for(i=0; i<q; i++) {
        char strtmp0[5]={0}, strtmp1[5]={0};
        scanf("%s", strtmp0); str0.push_back(strtmp0[0]);
        scanf("%s", strtmp1); str1.push_back(strtmp1[0]);
    }

    
    int limit[2]={0};    // left, right
    int k;
    for(k=0; k<2; k++) {
        int l=-1, r=n;
        while(r-l>1) {
            int m=(l+r)/2;
            int curr=m;
            int status=0;
            for(i=0; i<q; i++) {
                if(str[curr]==str0[i]) {
                    if(str1[i]=='L') curr--;
                    else             curr++;
                    if(curr<0) {
                        status=-1;
                        break;
                    }
                    else if(curr>=n) {
                        status=1;
                        break;
                    }
                }
            }
            if(k==0) {
                if(status<0) l=m;
                else         r=m;
            }
            else {
                if(status<=0) l=m;
                else          r=m;
            }
        }
        limit[k]=(k==0? l: r);
    }
    
    printf("%d\n", MAX(0, limit[1]-limit[0]-1));
    return 0;
}
