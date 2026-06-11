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
    int n,K;
    scanf("%d%d", &n, &K);
    vector<int> a(n);
    vector<ll> s(n+1);
    int i,j;
    for(i=0; i<n; i++) {
        scanf("%d", &a[i]);
        s[i+1]=s[i]+a[i];
    }
    vector<ll> v;
    for(i=0; i<=n; i++) {
        for(j=i+1; j<=n; j++) {
            v.push_back(s[j]-s[i]);
        }
    }
    set<pair<ll,int> > z;
    for(i=0; i<(int)v.size(); i++) {
        z.insert(make_pair(v[i],i));
    }

    ll ans=0;
    int k;
    for(k=50; k>=0; k--) {
        set<pair<ll,int> > z0;
        int cnt=0;
        auto it=z.begin();
        for(; it!=z.end(); ++it) {
            ll tmp=it->first;
            if(tmp & ((ll)1<<k)) {
                z0.insert(*it);
                cnt++;
            }
        }
        if(cnt>=K) {
            ans=ans*2+1;
            z.swap(z0);
        }
        else {
            ans=ans*2;
        }
    }
    printf("%lld\n", ans);

    return 0;
}

