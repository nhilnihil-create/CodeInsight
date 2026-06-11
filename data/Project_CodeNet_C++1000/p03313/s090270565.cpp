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
const int MAXN = 1<<19;

int A[MAXN];
int n;

void mxze(int &a, int b){
    a = max(a,b);
}
void mnze(int &a, int b){
    a = min(a,b);
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    ri(n);
    FOR(i,0,1<<n) ri(A[i]);

    int ans = 0;
    FOR(mask,1,1<<n){
        int mxi = A[0], mxi2 = -1;
        for(int s = 0 ; s = (s - mask) & mask ;) {
            if(mxi < A[s]) mxi2 = mxi, mxi = A[s];
            else if(mxi2 == -1 || mxi2 < A[s]) mxi2 = A[s];
        }
        mxze(ans, mxi + mxi2);
        printf("%d\n", ans);
    }

    return 0;
}
