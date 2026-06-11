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
    int n;
    scanf("%d", &n);

    vector<int> a(n);
    int i;
    for(i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a.begin(), a.end());

    for(i=0; i<n; i+=2) {
        a[i]=24-a[i];
    }
    sort(a.begin(), a.end());

    int min=MIN(a[0], 24-a[n-1]);
    for(i=1; i<n; i++) {
        min=MIN(min,a[i]-a[i-1]);
    }
    printf("%d\n", min);


    return 0;
}