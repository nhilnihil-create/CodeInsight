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

ll dp[20001];

int main(int argc, char* argv[])
{
    int n;
    scanf("%d", &n);

    vector<int> w(n),s(n),v(n);
    vector<pair<int,int> > z;
    int i;
    for(i=0; i<n; i++) {
        scanf("%d%d%d", &w[i], &s[i], &v[i]);
        z.push_back(make_pair(w[i]+s[i],i));
    }
    sort(z.begin(), z.end());

    int j;
    for(j=1; j<=20000; j++) {
        dp[j]=0;
    }

    for(i=0; i<n; i++) {
        int id=z[i].second;
        for(j=s[id]; j>=0; j--) {
           dp[j+w[id]]=MAX(dp[j+w[id]], dp[j]+v[id]);
        }
    }

    ll ans=0;
    for(j=20000; j>=0; j--) {
        ans=MAX(ans,dp[j]);
    }
    printf("%lld\n", ans);

    return 0;
}
