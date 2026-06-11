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
#define LINF 9223372036854775807
#define INF 2147483647
#define MOD 1000000007
using namespace std;

vector<long> pp;

void preparePrime( long maxp )
{
    long i;
    vector<long> a(maxp+1);
    for(i=2; i<=maxp; i++) {
        long k=i+i;
        while(k<=maxp) {
            a[k]=1;
            k+=i;
        }
    }
    for(i=2; i<=maxp; i++) {
        if(a[i]==0) pp.push_back( i );
    }
    return;
}

void decompositPrime( ll a, vector<pair<ll,ll> >& vv )
{
    preparePrime( (long)sqrt((double)a) );

    long i;
    for(i=0; i<(long)pp.size(); i++) {
        long count = 0;
        while(a % pp[i] == 0 ) {
            a /= pp[i];
            count ++;
        }
        if(count>0) vv.push_back( make_pair( pp[i], count ) );
        if (a==1) break;
    }
    if(a>1) {
        vv.push_back( make_pair( a, 1 ) );
    }

    return;
}

int main(int argc, char* argv[])
{
    long n;
    ll  p;
    scanf("%ld%lld", &n, &p);

    vector<pair<ll,ll> > vv;
    decompositPrime( p, vv );

    ll ans=1;
    long i;
    for(i=0; i<(long)vv.size(); i++) {
        ll tmp = vv[i].second / n;
        while(tmp>0) {
            ans *= vv[i].first;
            tmp--;
        }
    }

    printf("%lld\n", ans);

    return 0;
}
