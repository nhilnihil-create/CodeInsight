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



int main(int argc, char* argv[])
{
    long n;
    scanf("%ld", &n);

    vector<long> left(n);
    vector<long> right(n);
    long i;
    for(i=0; i<n; i++) {
        scanf("%ld%ld", &left[i], &right[i]);
    }
    sort(left.rbegin(), left.rend());
    sort(right.begin(), right.end());

    // left
    ll ans0=0, ans1=0;
    {
        long curr = 0;
        for(i=0; i<n; i++) {
            if(left[i]<=curr) break;
            ans0 += (left[i] - curr);
            curr = left[i];

            if(right[i]>=curr) break;
            ans0 += (curr - right[i]);
            curr = right[i];
        }
        ans0 += abs(curr);
        //printf("ans=%lld\n", ans0);
    }

    // right
    {
        long curr = 0;
        for(i=0; i<n; i++) {
            if(right[i]>=curr) break;
            ans1 += (curr - right[i]);
            curr = right[i];

            if(left[i]<=curr) break;
            ans1 += (left[i] - curr);
            curr = left[i];
        }
        ans1 += abs(curr);
        //printf("ans=%lld\n", ans1);
    }
    printf("%lld\n", MAX(ans0, ans1));

    return 0;
}

