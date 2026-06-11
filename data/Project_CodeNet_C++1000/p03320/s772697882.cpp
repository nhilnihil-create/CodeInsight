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
//const long long MOD = 998244353;

using namespace std;


int main(int argc, char* argv[])
{
    int K;
    scanf("%d", &K);

    set<ll> ans;
    int i,j;
    for(i=1; i<10; i++) {
        ans.insert(i);
    }
    ll base=1;
    for(i=1; i<=15; i++) {
        base*=10;
        for(j=1; j<=300; j++) {
            int curr=j;
            int sum=0;
            while(curr) {
                sum+=curr%10;
                curr/=10;
            }
            if(j+1<=sum+9*i) {
                ans.insert((j+1)*base-1);
            }
        }
    }
    int cnt=0;
    auto it=ans.begin();
    for(; it!=ans.end(); ++it) {
        printf("%lld\n", *it);
        cnt++;
        if(cnt==K) break;
    }

    return 0;
}

