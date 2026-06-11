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
 

int main(int argc, char* argv[])
{
    int n,m;
    scanf("%d%d", &n, &m);
    map<int,vector<pair<int,int> > > z;
    int i;
    for(i=0; i<n; i++) {
        int s,t,c;
        scanf("%d%d%d", &s, &t, &c);
        z[c].push_back(make_pair(s,t));
    }
    vector<int> a(100005);
    auto it=z.begin();
    for(; it!=z.end(); ++it) {
        vector<pair<int,int> >& vv=it->second;
        sort(vv.begin(), vv.end());

        int k;
        for(k=0; k<(int)vv.size(); k++) {
            if(k==0 || vv[k-1].second!=vv[k].first) {
                a[vv[k].first-1]++;
                a[vv[k].second]--;
            }
            else {
                a[vv[k].first]++;
                a[vv[k].second]--;
            }
        }
    }

    ll max=0;
    ll sum=0;
    for(i=0; i<=100000; i++) {
        sum+=a[i];
        max=MAX(max,sum);
    }
    printf("%lld\n", max);

    return 0;
}