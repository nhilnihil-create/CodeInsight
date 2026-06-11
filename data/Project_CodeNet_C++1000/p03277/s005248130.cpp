#include <iostream>
#include <stdio.h>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <algorithm>
#include <math.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define FOR(i,n,m) for(int i=n; i<(int)m; i++)
#define ROF(i,n,m) for(int i=n; i>(int)m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second
#define ri(a) scanf("%d",&a)
#define rii(a,b) ri(a),ri(b)
#define riii(a,b,c) rii(a,b),ri(c)
#define lri(a) scanf("%lld",&a)
#define lrii(a,b) lri(a),lri(b)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define all(x) x.begin(),x.end()
#define debug true
#define dprintf debug && printf

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9+7;
const int MAXN = 3e5+5;

ll BIT[MAXN];

void updBIT(int p, ll val){
    p += MAXN/2;
    for(; p < MAXN; p += p&-p) BIT[p] += val;
}

ll sumBIT(int p){
    p += MAXN/2;
    ll ret = 0;
    for(; p; p -= p&-p) ret += BIT[p];
    return ret;
}

int a[MAXN];
int n;

ll count(int x){
    ms(BIT, 0);
    int acum = 0;
    ll ret = 0;
    updBIT(0, 1);
    FOR(i,0,n){
        acum += (a[i] > x ? -1 : 1);
        ret += sumBIT(acum-1);
        updBIT(acum, 1);
    } 
    return ret;
} 

ll sum(ll x){
    return (x*(x+1))/2;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    ri(n);
    FOR(i,0,n) ri(a[i]);

    int l = 0, r = INF;
    while(l < r){
        int mid = (l+r)>>1;
        if(count(mid) >= sum(n)/2 + 1) r = mid;
        else l = mid + 1;
    }
    printf("%d\n", r);

    return 0;
}
